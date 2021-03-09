/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 19:34:44 by sehattor          #+#    #+#             */
/*   Updated: 2020/10/14 00:42:43 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	l_f(int m, const char *str)
{
	int	size;

	size = 0;
	while (ft_isdigit(str[size]))
		size++;
	if ((m == -1 && size > 19))
		return (0);
	if ((m == 1 && size > 19))
		return (-1);
	if ((m == -1 && ft_strncmp(str, "9223372036854775808", 19) > 0)
		&& size == 19)
		return (0);
	if ((m == 1 && ft_strncmp(str, "9223372036854775807", 19) > 0)
		&& size == 19)
		return (-1);
	return (1);
}

int			ft_atoi(const char *str)
{
	int	i;
	int	m;
	int	ans;

	i = 0;
	m = 1;
	ans = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' ||
			str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		m = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (1 != l_f(m, str + i))
		return (l_f(m, str + i));
	while ('0' <= str[i] && str[i] <= '9')
	{
		ans *= 10;
		ans += str[i++] - '0';
	}
	return (ans * m);
}
