/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_readfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:46:42 by sehattor          #+#    #+#             */
/*   Updated: 2021/03/13 15:55:27 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_img(void *mlx, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
		&img->llen, &img->endian);
}

int		read_num(int *i, char **str)
{
	while (ft_isspace(**str))
		(*str)++;
	*i = ft_atoi(*str);
	if (!ft_isdigit(**str))
		return (0);
	while (ft_isdigit(**str))
		(*str)++;
	return (1);
}

void	read_r(t_god *g, char *str)
{
	int	ret;
	int	w;

	ret = 1;
	if (g->isr)
		return (set_err(g, "R error\n"));
	g->isr = 1;
	str++;
	ret &= read_num(&w, &str);
	g->scr_w = ft_min(g->scr_w, w);
	ret &= read_num(&w, &str);
	g->scr_h = ft_min(g->scr_h, w);
	if (g->scr_w <= 0 || g->scr_h <= 0 || !ret)
		return (set_err(g, "R Size error\n"));
}

void	read_cf(t_god *g, char *str)
{
	size_t	*color;
	int		r;
	int		green;
	int		b;
	int		ret;

	ret = 1;
	color = *str == 'C' ? &g->ceil_color : &g->floor_color;
	str++;
	ret &= read_num(&r, &str);
	str += *str == ',' ? 1 : 0;
	ret &= read_num(&green, &str);
	str += *str == ',' ? 1 : 0;
	ret &= read_num(&b, &str);
	if (*color)
		return (set_err(g, "C or F error\n"));
	if (r < 0 || 255 < r || green < 0 || 255 < green
		|| b < 0 || 255 < b || *str || !ret)
		return (set_err(g, "C or F error\n"));
	*color = create_color(255, r, green, b);
}

void	read_img(t_god *g, t_img *img, char *str)
{
	char	*path;

	if (img->img)
		return (set_err(g, "EA WE SO NO error\n"));
	path = ft_strtrim(str, SPACE);
	img->img = mlx_xpm_file_to_image(g->mlx, path, &img->width, &img->height);
	if (!img->img)
		return (set_err(g, "MLX error\n"));
	else
		img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->llen, &img->endian);
	free(path);
}
