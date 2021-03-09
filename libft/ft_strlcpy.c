/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 23:10:47 by sehattor          #+#    #+#             */
/*   Updated: 2020/10/10 22:30:40 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	cnt;

	cnt = 0;
	while (dstsize > 0 && cnt < dstsize - 1 && src[cnt] != '\0')
	{
		dst[cnt] = src[cnt];
		cnt++;
	}
	if (dstsize > 0)
		dst[cnt] = '\0';
	cnt = 0;
	while (src[cnt] != '\0')
		cnt++;
	return (cnt);
}
