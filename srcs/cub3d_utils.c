/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:56:43 by sehattor          #+#    #+#             */
/*   Updated: 2021/03/10 07:34:09 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_god *g, int x, int y, int color)
{
	char *dst;

	dst = g->w_img.addr + (y * g->w_img.llen + x * (g->w_img.bpp / 8));
	*(unsigned int *)dst = color;
}

size_t	create_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

size_t	pic_color(t_img img, int i, int j)
{
	if (0 <= i && i < img.width && 0 <= j && j <= img.height)
		return (*((unsigned int *)(img.addr + j * img.llen) + i));
	else
		return (0);
}

t_ipair	*make_ipair(int i, int j)
{
	t_ipair	*p;

	p = (t_ipair*)malloc(sizeof(t_ipair));
	p->first = i;
	p->second = j;
	return (p);
}
