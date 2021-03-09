/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:55:28 by sehattor          #+#    #+#             */
/*   Updated: 2021/03/02 14:55:28 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	paint_cf(t_god *g)
{
	int	x;
	int	y;

	x = 0;
	while (x++ < g->scr_w)
	{
		y = 0;
		while (y++ < g->scr_h / 2)
			my_mlx_pixel_put(g, x, y, g->ceil_color);
		while (y++ < g->scr_h)
			my_mlx_pixel_put(g, x, y, g->floor_color);
	}
}

void	wall_verline(t_god *g, int x)
{
	t_dpair	st_end;
	t_dpair	texture_p;
	size_t	color;
	int		y;

	st_end.first = -(int)(g->scr_h / g->perpwalldist) / 2 + g->scr_h / 2;
	st_end.second = (int)(g->scr_h / g->perpwalldist) / 2 + g->scr_h / 2;
	texture_p.first = (int)(g->wallx * (double)(g->ch_img->width));
	y = st_end.first;
	while (y <= st_end.second)
	{
		texture_p.second = (int)((double)(y - st_end.first) /
			(st_end.second - st_end.first) * g->ch_img->height);
		color = pic_color(*g->ch_img, texture_p.first, texture_p.second);
		if (0 <= y && y < g->scr_h)
			my_mlx_pixel_put(g, x, y, color);
		y++;
	}
}

t_img	*choice_tex(t_god *g)
{
	if (g->side == 0 && g->raydirx < 0)
		return (&g->no_img);
	if (g->side == 0 && g->raydirx > 0)
		return (&g->so_img);
	if (g->side == 1 && g->raydiry > 0)
		return (&g->ea_img);
	if (g->side == 1 && g->raydiry < 0)
		return (&g->we_img);
	return (NULL);
}

t_dpair	convert_trans(t_god *g, int i, int j)
{
	t_dpair	transform;
	t_dpair	s_pos;
	double	invdet;

	s_pos.first = i + 0.5 - g->pl.x;
	s_pos.second = j + 0.5 - g->pl.y;
	invdet = (1.0 / (g->planex * g->pl.diry - g->pl.dirx * g->planey));
	transform.first =
		invdet * (g->pl.diry * s_pos.first - g->pl.dirx * s_pos.second);
	transform.second =
		invdet * (-g->planey * s_pos.first + g->planex * s_pos.second);
	return (transform);
}