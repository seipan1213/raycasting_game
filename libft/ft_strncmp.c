/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 14:48:39 by sehattor          #+#    #+#             */
/*   Updated: 2020/10/12 01:34:49 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cnt;

	cnt = 0;
	if (n == 0)
		return (0);
	while (s1[cnt] && s2[cnt] && cnt < n - 1)
	{
		if (s1[cnt] != s2[cnt])
			return ((unsigned char)s1[cnt] - (unsigned char)s2[cnt]);
		cnt++;
	}
	return ((unsigned char)s1[cnt] - (unsigned char)s2[cnt]);
}
