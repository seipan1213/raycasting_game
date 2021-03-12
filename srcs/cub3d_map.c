/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:43:57 by sehattor          #+#    #+#             */
/*   Updated: 2021/03/12 15:05:54 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	bfs_clear(t_god *g, int **map, t_list **lst, int error)
{
	int	c;

	c = 0;
	while (c < g->map_h)
		free(map[c++]);
	free(map);
	if (error)
		set_err(g, "map error\n");
	ft_lstclear(lst, &free);
	free(lst);
}

void	map_bfs(t_god *g, int **map, t_ipair p)
{
	const int	dx[4] = {0, 1, 0, -1};
	const int	dy[4] = {1, 0, -1, 0};
	int			c;
	t_list		**lst;

	lst = (t_list **)ft_calloc(1, sizeof(t_list *));
	*lst = ft_lstnew(make_ipair(p.first, p.second));
	while (*lst)
	{
		p = *(t_ipair *)(*lst)->content;
		ft_lstdel_front(lst);
		c = -1;
		if (p.first <= 0 || p.second <= 0 ||
				p.first >= g->map_h - 1 || p.second >= g->map_w - 1)
			return (bfs_clear(g, map, lst, 1));
		while (++c < 4)
			if (g->map[p.first + dx[c]][p.second + dy[c]] != '1'
					&& map[p.first + dx[c]][p.second + dy[c]] == 0)
			{
				ft_lstadd_back(lst, ft_lstnew(make_ipair(p.first + dx[c],
					p.second + dy[c])));
				map[p.first + dx[c]][p.second + dy[c]] = 1;
			}
	}
	bfs_clear(g, map, lst, 0);
}

void	map_isclose(t_god *g, t_ipair p)
{
	int	**map;
	int	i;
	int	j;

	i = 0;
	if (!(map = (int **)malloc(sizeof(int *) * g->map_h)))
		return (set_err(g, "malloc error\n"));
	while (i < g->map_h)
	{
		j = 0;
		if (!(map[i] = (int *)malloc(sizeof(int) * g->map_w)))
		{
			while (i-- > 0)
				free(map[i]);
			free(map);
			return (set_err(g, "malloc error\n"));
		}
		while (j < g->map_w)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
	map_bfs(g, (int **)map, p);
}

void	check_map(t_god *g)
{
	int		i;
	int		j;
	int		is_pl;
	t_ipair	p;

	i = -1;
	is_pl = 0;
	while (++i < g->map_h)
	{
		j = -1;
		while (++j < g->map_w)
		{
			if (ft_strchr("NSWE", g->map[i][j]))
			{
				if (is_pl || !(is_pl = 1))
					set_err(g, "map error\n");
				set_pl(g, i, j);
				p.first = i;
				p.second = j;
			}
		}
	}
	if (is_pl == 0)
		set_err(g, "map error\n");
	map_isclose(g, p);
}

void	make_map(t_god *g)
{
	int		i;
	t_list	*lst;

	if (!(g->map = (char**)malloc(sizeof(char*) * (g->map_h + 1))))
		return ;
	*(g->map + g->map_h) = 0;
	lst = g->map_list;
	i = 0;
	while (i < g->map_h)
	{
		if (!(g->map[i] = malloc(sizeof(char) * (g->map_w + 1))))
			return ;
		ft_memset(g->map[i], ' ', g->map_w);
		ft_memcpy(g->map[i], lst->content, ft_strlen(lst->content));
		g->map[i][g->map_w] = 0;
		lst = lst->next;
		i++;
	}
	check_map(g);
}
