/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:48:42 by sehattor          #+#    #+#             */
/*   Updated: 2021/03/10 15:43:12 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_err(t_god *g, char *str)
{
	char	*tmp;

	g->exit = 1;
	if (!g->err_msg)
		g->err_msg = ft_strdup("ERROR\n");
	if (g->err_msg)
	{
		tmp = g->err_msg;
		g->err_msg = ft_strjoin(g->err_msg, str);
		free(tmp);
	}
	if (!g->err_msg)
	{
		write(2, "ERROR\nmalloc error!!!\n", 22);
		exit(0);
	}
}

void	destory_g(t_god *g)
{
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->w_img.img)
		mlx_destroy_image(g->mlx, g->w_img.img);
	if (g->s_img.img)
		mlx_destroy_image(g->mlx, g->s_img.img);
	if (g->ea_img.img)
		mlx_destroy_image(g->mlx, g->ea_img.img);
	if (g->we_img.img)
		mlx_destroy_image(g->mlx, g->we_img.img);
	if (g->so_img.img)
		mlx_destroy_image(g->mlx, g->so_img.img);
	if (g->no_img.img)
		mlx_destroy_image(g->mlx, g->no_img.img);
	if (g->map_list)
		ft_lstclear(&g->map_list, &free);
	while (g->map_h + 1 && g->map)
		free(*(g->map + g->map_h--));
	free(g->map);
	free(g->err_msg);
	free(g->cub_name);
	free(g->mlx);
	ft_bzero(g, sizeof(t_god));
}

void	exit_g(t_god *g)
{
	if (g->err_msg)
		write(1, g->err_msg, ft_strlen(g->err_msg));
	destory_g(g);
	exit(0);
}
