/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:14:04 by sehattor          #+#    #+#             */
/*   Updated: 2020/10/11 21:39:17 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	s_len = 0;
	while (s[s_len])
		s_len++;
	if (start > s_len)
	{
		if (!(sub = (char*)malloc(sizeof(char))))
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	if (!(sub = (char*)malloc(len * sizeof(char) + 1)))
		return (NULL);
	sub[len] = '\0';
	while (len--)
		sub[len] = s[start + len];
	return (sub);
}
