/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:26:47 by sehattor          #+#    #+#             */
/*   Updated: 2021/03/10 15:43:32 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_god(t_god *g)
{
	if (g->scr_w > 0 && g->scr_h > 0)
		g->win = mlx_new_window(g->mlx, g->scr_w, g->scr_h, g->cub_name);
	if (!g->win)
		set_err(g, "Error creating MLX window.\n");
	g->w_img.img = mlx_new_image(g->mlx, g->scr_w, g->scr_w);
	g->w_img.addr = mlx_get_data_addr(g->w_img.img, &g->w_img.bpp,
									&g->w_img.llen, &g->w_img.endian);
	mlx_do_key_autorepeatoff(g->mlx);
}

int		keypress_hook(int keycode, t_god *g)
{
	if (keycode == KEY_CODE_W)
		g->pl.movespeed_fb = MOVESPEED;
	if (keycode == KEY_CODE_S)
		g->pl.movespeed_fb = -MOVESPEED;
	if (keycode == KEY_CODE_D)
		g->pl.movespeed_rl = MOVESPEED;
	if (keycode == KEY_CODE_A)
		g->pl.movespeed_rl = -MOVESPEED;
	if (keycode == KEY_CODE_RA)
		g->pl.rotspeed = -ROTSPEED;
	if (keycode == KEY_CODE_LA)
		g->pl.rotspeed = ROTSPEED;
	if (keycode == KEY_CODE_ESC)
		g->exit = 1;
	return (0);
}

int		exit_hook(t_god *g)
{
	g->exit = 1;
	return (0);
}

int		keyrelease_hook(int keycode, t_god *g)
{
	if (keycode == KEY_CODE_W)
		g->pl.movespeed_fb = 0;
	if (keycode == KEY_CODE_S)
		g->pl.movespeed_fb = 0;
	if (keycode == KEY_CODE_D)
		g->pl.movespeed_rl = 0;
	if (keycode == KEY_CODE_A)
		g->pl.movespeed_rl = 0;
	if (keycode == KEY_CODE_RA)
		g->pl.rotspeed = 0;
	if (keycode == KEY_CODE_LA)
		g->pl.rotspeed = 0;
	return (0);
}

int		main(int argc, char **argv)
{
	t_god	g;

	ft_bzero(&g, sizeof(t_god));
	g.mlx = mlx_init();
	if (!g.mlx)
		set_err(&g, "MLX error\n");
	load_file(&g, argc, argv);
	if (g.err_msg)
		exit_g(&g);
	init_god(&g);
	if (g.err_msg)
		exit_g(&g);
	mlx_hook(g.win, X_E_P, X_M_P, &keypress_hook, &g);
	mlx_hook(g.win, X_E_R, X_M_R, &keyrelease_hook, &g);
	mlx_hook(g.win, X_E_E, X_M_E, &exit_hook, &g);
	mlx_loop_hook(g.mlx, &update, &g);
	mlx_loop(g.mlx);
}
