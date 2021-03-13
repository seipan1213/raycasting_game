/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:17:32 by sehattor          #+#    #+#             */
/*   Updated: 2021/03/13 15:32:29 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	playermove(t_god *g)
{
	double	oldplanex;
	double	olddirx;

	if (g->map[(int)(g->pl.x + g->pl.dirx * g->pl.movespeed_fb)]
		[(int)(g->pl.y)] != '1')
		g->pl.x += g->pl.dirx * g->pl.movespeed_fb;
	if (g->map[(int)(g->pl.x)]
		[(int)(g->pl.y + g->pl.diry * g->pl.movespeed_fb)] != '1')
		g->pl.y += g->pl.diry * g->pl.movespeed_fb;
	if (g->map[(int)(g->pl.x + g->planex * g->pl.movespeed_rl)]
		[(int)(g->pl.y)] != '1')
		g->pl.x += g->planex * g->pl.movespeed_rl;
	if (g->map[(int)(g->pl.x)]
		[(int)(g->pl.y + g->planey * g->pl.movespeed_rl)] != '1')
		g->pl.y += g->planey * g->pl.movespeed_rl;
	olddirx = g->pl.dirx;
	g->pl.dirx = g->pl.dirx * cos(g->pl.rotspeed) -
		g->pl.diry * sin(g->pl.rotspeed);
	g->pl.diry = olddirx * sin(g->pl.rotspeed) +
		g->pl.diry * cos(g->pl.rotspeed);
	oldplanex = g->planex;
	g->planex = g->planex * cos(g->pl.rotspeed) -
		g->planey * sin(g->pl.rotspeed);
	g->planey = oldplanex * sin(g->pl.rotspeed) +
		g->planey * cos(g->pl.rotspeed);
}

int		update(t_god *g)
{
	playermove(g);
	paint_cf(g);
	raycast(g);
	if (g->bmp)
		write_bmp(g);
	if (g->exit)
		exit_g(g);
	mlx_put_image_to_window(g->mlx, g->win, g->w_img.img, 0, 0);
	mlx_do_sync(g->mlx);
	return (0);
}

void	set_pl(t_god *g, int i, int j)
{
	double	r;
	double	tmp;

	g->pl.x = i + 0.5;
	g->pl.y = j + 0.5;
	g->pl.dirx = -1;
	g->pl.diry = 0;
	g->planex = 0;
	g->planey = (double)g->scr_w / (double)g->scr_h / 2.0;
	r = 0;
	if (g->map[i][j] == 'S')
		r = M_PI;
	else if (g->map[i][j] == 'W')
		r = M_PI_2;
	else if (g->map[i][j] == 'E')
		r = -M_PI_2;
	tmp = g->planex;
	g->planex = g->planex * cos(r) - g->planey * sin(r);
	g->planey = tmp * sin(r) + g->planey * cos(r);
	tmp = g->pl.dirx;
	g->pl.dirx = g->pl.dirx * cos(r) - g->pl.diry * sin(r);
	g->pl.diry = tmp * sin(r) + g->pl.diry * cos(r);
}
