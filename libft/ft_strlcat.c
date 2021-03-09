/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 23:46:58 by sehattor          #+#    #+#             */
/*   Updated: 2020/10/14 00:33:10 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	int		cnt;

	dst_len = 0;
	src_len = 0;
	cnt = 0;
	while (dst[dst_len] != '\0')
		dst_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	while (src[cnt] != '\0' && dst_len + cnt < dstsize - 1)
	{
		dst[dst_len + cnt] = src[cnt];
		cnt++;
	}
	dst[dst_len + cnt] = '\0';
	return (dst_len + src_len);
}
