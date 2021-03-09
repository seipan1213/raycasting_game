/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:53:02 by sehattor          #+#    #+#             */
/*   Updated: 2021/03/02 14:53:02 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_sprite(t_god *g, int x, int *ymask, t_drawline dl)
{
	int		y;
	int		d;
	size_t	color;
	t_ipair	tex;

	tex.first = (int)(((double)x - (-dl.spriteheight / 2 + dl.spritescreenx)) *
							(double)g->s_img.width / (double)dl.spriteheight);
	y = dl.drawstarty;
	while (y <= dl.drawendy)
	{
		d = (double)y - g->scr_h / 2 + dl.spriteheight / 2;
		tex.second = (int)((d * g->s_img.height) / dl.spriteheight);
		color = pic_color(g->s_img, tex.first, tex.second);
		if (color != g->i_zero_color && ymask[y] == 0)
		{
			ymask[y] = 1;
			my_mlx_pixel_put(g, x, y, color);
		}
		y++;
	}
}

void	make_sprite(t_god *g, int x, int *ymask, t_ipair *s_pos)
{
	t_drawline dl;

	dl.transform = convert_trans(g, s_pos->first, s_pos->second);
	dl.spritescreenx = (int)((g->scr_w / 2) *
								(1 + dl.transform.first / dl.transform.second));
	dl.spriteheight = ABS((int)(g->scr_h / (dl.transform.second)));
	dl.drawstarty = MAX(0, -dl.spriteheight / 2 + g->scr_h / 2);
	dl.drawendy = MIN(dl.spriteheight / 2 + g->scr_h / 2, g->scr_h - 1);
	if (dl.transform.second <= 0)
		return ;
	if (x < -dl.spriteheight / 2 + dl.spritescreenx ||
			dl.spriteheight / 2 + dl.spritescreenx <= x)
		return ;
	put_sprite(g, x, ymask, dl);
}

void	sprite_verline(t_god *g, int x, int *mx)
{
	int		i;
	t_ipair	s_pos;
	int		ymask[g->scr_h];

	ft_bzero(ymask, sizeof(int) * g->scr_h);
	g->i_zero_color = pic_color(g->s_img, 0, 0);
	i = 0;
	while (mx[2 * i])
	{
		s_pos.first = mx[2 * i];
		s_pos.second = mx[2 * i + 1];
		make_sprite(g, x, ymask, &s_pos);
		i++;
	}
	free(mx);
}