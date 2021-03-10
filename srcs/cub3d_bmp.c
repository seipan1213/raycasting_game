/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:47:37 by sehattor          #+#    #+#             */
/*   Updated: 2021/03/10 07:28:53 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	littleendian(unsigned char *s, unsigned int n, int size)
{
	int	i;

	i = 0;
	s[i++] = (unsigned char)(n);
	while (i < size)
		s[i++] = (unsigned char)(n >>= 8);
}

void	write_header(t_god *g, int fd)
{
	unsigned char	header[BMP_FILEHEADER_SIZE + BMP_INFHEADER_SIZE];

	ft_bzero(header, BMP_FILEHEADER_SIZE + BMP_INFHEADER_SIZE);
	ft_memcpy(header, "BM", 2);
	littleendian(header + 2, BMP_FILEHEADER_SIZE +
		BMP_INFHEADER_SIZE + (BMP_BPP * g->scr_w * g->scr_h), 4);
	littleendian(header + 10, BMP_FILEHEADER_SIZE + BMP_INFHEADER_SIZE, 4);
	littleendian(header + 14, BMP_INFHEADER_SIZE, 4);
	littleendian(header + 18, g->scr_w, 4);
	littleendian(header + 22, g->scr_h, 4);
	littleendian(header + 26, BMP_PLANES, 2);
	littleendian(header + 28, BMP_BPP * 8, 2);
	write(fd, header, BMP_FILEHEADER_SIZE + BMP_INFHEADER_SIZE);
}

void	write_body(t_god *g, int fd)
{
	int				w;
	int				h;
	unsigned char	*line;

	h = g->scr_h;
	if (!(line = (unsigned char *)ft_calloc(g->scr_w,
				sizeof(unsigned char) * BMP_BPP)))
		return (set_err(g, "bmp malloc error\n"));
	while (--h >= 0)
	{
		w = -1;
		while (++w < g->scr_w)
			littleendian(line + w * BMP_BPP,
				*((unsigned int *)(g->w_img.addr + h * g->w_img.llen) + w), 4);
		write(fd, line, g->scr_w * BMP_BPP);
	}
	free(line);
}

void	write_bmp(t_god *g)
{
	int		fd;
	char	*name;

	g->exit = 1;
	if (!(name = ft_strdup(g->cub_name)))
		return (set_err(g, "bmp malloc error\n"));
	ft_memcpy(name + ft_strlen(name) - 3, "bmp", 3);
	if ((fd = open(name, O_CREAT | O_WRONLY, S_IREAD | S_IWRITE)) < 0)
		return (set_err(g, "bmp create error\n"));
	write_header(g, fd);
	write_body(g, fd);
	close(fd);
	free(name);
}
