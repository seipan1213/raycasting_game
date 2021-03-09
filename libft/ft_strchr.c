/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 23:58:56 by sehattor          #+#    #+#             */
/*   Updated: 2020/10/12 23:43:54 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int	cnt;

	cnt = 0;
	while (s[cnt] != '\0')
	{
		if (s[cnt] == c)
			return ((char*)(s + cnt));
		cnt++;
	}
	if (s[cnt] == c)
		return ((char*)(s + cnt));
	return (NULL);
}
