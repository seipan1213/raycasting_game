/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:19:23 by sehattor          #+#    #+#             */
/*   Updated: 2020/10/30 23:21:59 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_free(char *save)
{
	free(save);
	return (NULL);
}

char	*read_fd(int fd, char *save)
{
	char	*tmp;
	char	*buf;
	int		ret;

	if (!(buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (NULL);
	if (!save && !(save = ft_strdup("\0")))
	{
		free(buf);
		return (NULL);
	}
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(save, buf);
		if (save)
			free(save);
		save = tmp;
		if (!tmp || ft_strchr(save, '\n'))
			break ;
	}
	free(buf);
	if (ret < 0)
		return (save = save_free(save));
	return (save);
}

char	*save_line(char *save, char *line, int *ret)
{
	char	*tmp;

	tmp = ft_strchr(line, '\n');
	free(save);
	save = NULL;
	if (!tmp)
	{
		*ret = 0;
		return (NULL);
	}
	return (ft_strdup(tmp + 1));
}

char	*get_line(char *line)
{
	char	*tmp;

	tmp = ft_strchr(line, '\n');
	if (!tmp)
		return (line);
	*tmp = '\0';
	tmp = ft_strdup(line);
	free(line);
	line = NULL;
	return (tmp);
}

int		get_next_line(int fd, char **line)
{
	static char	*save[256];
	int			ret;

	ret = 1;
	if (0 > fd || fd > 256 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	*line = NULL;
	if (save[fd] != NULL)
	{
		if (!(*line = ft_strdup(save[fd])))
			return (-1);
		if (ft_strchr(*line, '\n'))
		{
			save[fd] = save_line(save[fd], *line, &ret);
			*line = get_line(*line);
			return (ret);
		}
	}
	if (!(*line = read_fd(fd, *line)))
		return (-1);
	save[fd] = save_line(save[fd], *line, &ret);
	*line = get_line(*line);
	return (ret);
}
