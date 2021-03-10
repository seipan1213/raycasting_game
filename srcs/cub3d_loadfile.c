/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_loadfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:39:01 by sehattor          #+#    #+#             */
/*   Updated: 2021/03/10 07:29:51 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		is_map(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr(MAPCHAR, str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	analyze_line(t_god *g, char *line)
{
	char	*str;
	int		str_len;

	if (!(str = ft_strtrim(line, SPACE)))
		return (set_err(g, "malloc error\n"));
	str_len = ft_strlen(str);
	if (str_len)
	{
		if (!ft_memcmp(str, "R ", 2))
			read_r(g, str);
		else if (!ft_memcmp(str, "C ", 2) || !ft_memcmp(str, "F ", 2))
			read_cf(g, str);
		else if (!ft_memcmp(str, "SO ", 3))
			read_img(g, &g->so_img, str + 3);
		else if (!ft_memcmp(str, "NO ", 3))
			read_img(g, &g->no_img, str + 3);
		else if (!ft_memcmp(str, "WE ", 3))
			read_img(g, &g->we_img, str + 3);
		else if (!ft_memcmp(str, "EA ", 3))
			read_img(g, &g->ea_img, str + 3);
		else if (!ft_memcmp(str, "S ", 2))
			read_img(g, &g->s_img, str + 2);
	}
	free(line);
	free(str);
}

void	analyze_map(t_god *g, char *line)
{
	char	*str;

	if (!(str = ft_strtrim(line, SPACE)))
		return ;
	if (is_map(str))
	{
		ft_lstadd_back(&g->map_list, ft_lstnew(ft_strdup(line)));
		g->map_h++;
		g->map_w = fmax(g->map_w, (int)ft_strlen(line));
	}
	free(line);
	free(str);
}

void	check_file(t_god *g, int fd)
{
	close(fd);
	if (!g->ceil_color || !g->floor_color || !g->map_h || !g->map_w ||
			!g->scr_h || !g->scr_w || !g->so_img.img || !g->no_img.img ||
			!g->we_img.img || !g->ea_img.img || !g->s_img.img)
		return (set_err(g, "incomplete cubfile\n"));
}

void	load_file(t_god *g, int argc, char **argv)
{
	int		fn_len;
	int		fd;
	char	*line;

	if (argc != 2 && argc != 3)
		return (set_err(g, "argument error\n"));
	fn_len = ft_strlen(argv[1]);
	if (fn_len <= 4 || ft_strncmp(argv[1] + fn_len - 4, ".cub", 4))
		return (set_err(g, "not cubfile\n"));
	if (argc == 3 && ft_strncmp(argv[2], "--save", ft_strlen(argv[2])))
		return (set_err(g, "argument error\n"));
	g->cub_name = ft_strdup(argv[1]);
	if (!g->cub_name || (fd = open(g->cub_name, O_RDONLY)) < 0)
		return (set_err(g, "file open error\n"));
	while (0 < get_next_line(fd, &line) && !is_map(line))
		analyze_line(g, line);
	analyze_map(g, line);
	while (0 < get_next_line(fd, &line))
		analyze_map(g, line);
	analyze_map(g, line);
	make_map(g);
	g->bmp = argc == 3 ? 1 : 0;
	check_file(g, fd);
}
