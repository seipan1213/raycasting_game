/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 20:14:05 by sehattor          #+#    #+#             */
/*   Updated: 2020/10/08 20:15:07 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	s_len;

	s_len = 0;
	while (s[s_len] != '\0')
		s_len++;
	write(fd, s, s_len);
	write(fd, "\n", 1);
}
