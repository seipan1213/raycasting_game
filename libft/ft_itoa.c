/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 23:56:13 by sehattor          #+#    #+#             */
/*   Updated: 2020/10/12 19:18:46 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static long	ft_abs(int n, int *m)
{
	long	num;

	*m = 0;
	num = n;
	if (num < 0)
	{
		num *= -1;
		*m = 1;
	}
	return (num);
}

static char	*zero_ma(void)
{
	char	*ans;

	if (!(ans = (char*)malloc(2 * sizeof(char))))
		return (NULL);
	ans[0] = '0';
	ans[1] = '\0';
	return (ans);
}

char		*ft_itoa(int n)
{
	char	*ans;
	long	num;
	int		i;
	int		m;

	if (n == 0)
		return (zero_ma());
	num = ft_abs(n, &m);
	i = 0;
	while (num > 0 && ++i)
		num /= 10;
	num = ft_abs(n, &m);
	if (!(ans = (char*)malloc((i + 1 + m) * sizeof(char))))
		return (NULL);
	ans[i + m] = '\0';
	if (m)
		ans[0] = '-';
	while (i--)
	{
		ans[i + m] = num % 10 + '0';
		num /= 10;
	}
	return (ans);
}
