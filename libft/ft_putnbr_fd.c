/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 20:47:14 by sehattor          #+#    #+#             */
/*   Updated: 2020/10/12 01:12:11 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	int		i;
	int		j;
	char	ans[13];

	num = n;
	i = 0;
	if (num < 0)
	{
		num = -num;
		write(fd, "-", 1);
	}
	while (num > 0 || i == 0)
	{
		ans[i++] = num % 10 + '0';
		num /= 10;
	}
	j = 0;
	while (j < i / 2)
	{
		n = ans[j];
		ans[j] = ans[i - j - 1];
		ans[i - (j++) - 1] = n;
	}
	write(fd, ans, i);
}
