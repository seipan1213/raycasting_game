/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:49:58 by sehattor          #+#    #+#             */
/*   Updated: 2021/03/10 16:15:37 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ray_hitsp(t_god *g, int *mx)
{
	int	mxi;

	mxi = 0;
	while (g->map[g->mapxy.first][g->mapxy.second] != '1')
	{
		if (g->map[g->mapxy.first][g->mapxy.second] == '2')
		{
			mx[mxi * 2] = g->mapxy.first;
			mx[mxi * 2 + 1] = g->mapxy.second;
			mxi++;
		}
		if (g->sdist.first < g->sdist.second)
		{
			g->sdist.first += g->ddist.first;
			g->mapxy.first += g->stepxy.first;
			g->side = 0;
		}
		else
		{
			g->sdist.second += g->ddist.second;
			g->mapxy.second += g->stepxy.second;
			g->side = 1;
		}
	}
}

void	ray_dist_step(t_god *g)
{
	if (g->raydirx < 0)
	{
		g->sdist.first = (g->pl.x - g->mapxy.first) * g->ddist.first;
		g->stepxy.first = -1;
	}
	else
	{
		g->sdist.first = (g->mapxy.first + 1.0 - g->pl.x) * g->ddist.first;
		g->stepxy.first = 1;
	}
	if (g->raydiry < 0)
	{
		g->sdist.second = (g->pl.y - g->mapxy.second) * g->ddist.second;
		g->stepxy.second = -1;
	}
	else
	{
		g->sdist.second = (g->mapxy.second + 1.0 - g->pl.y) * g->ddist.second;
		g->stepxy.second = 1;
	}
}

void	ray_calc(t_god *g, int x)
{
	int *mx;

	if (!(mx = ft_calloc(sizeof(int), ft_max(g->map_h, g->map_w) * 4)))
		return (set_err(g, "map malloc error\n"));
	ray_dist_step(g);
	ray_hitsp(g, mx);
	if (g->side == 0)
		g->perpwalldist = (g->mapxy.first - g->pl.x +
			(1 - g->stepxy.first) / 2) / g->raydirx;
	else
		g->perpwalldist = (g->mapxy.second - g->pl.y +
			(1 - g->stepxy.second) / 2) / g->raydiry;
	if (g->side == 0)
		g->wallx = g->pl.y + g->perpwalldist * g->raydiry;
	else
		g->wallx = g->pl.x + g->perpwalldist * g->raydirx;
	if ((g->side == 0 && g->raydirx > 0) || (g->side == 1 && g->raydiry < 0))
		g->wallx = 1 - g->wallx;
	g->wallx -= floor(g->wallx);
	g->ch_img = choice_tex(g);
	wall_verline(g, x);
	sprite_verline(g, x, mx);
}

void	raycast(t_god *g)
{
	int		x;
	double	cx;

	x = -1;
	while (++x < g->scr_w)
	{
		cx = 2 * x / (double)g->scr_w - 1;
		g->raydirx = g->pl.dirx + g->planex * cx;
		g->raydiry = g->pl.diry + g->planey * cx;
		g->mapxy.first = (int)(g->pl.x);
		g->mapxy.second = (int)(g->pl.y);
		g->ddist.first = fabs(1 / g->raydirx);
		g->ddist.second = fabs(1 / g->raydiry);
		ray_calc(g, x);
	}
}
