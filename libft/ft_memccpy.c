/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:48:25 by sehattor          #+#    #+#             */
/*   Updated: 2020/10/13 00:03:45 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*str_dst;
	const unsigned char	*str_src;
	size_t				cnt;

	str_dst = (unsigned char*)dst;
	str_src = (const unsigned char*)src;
	cnt = 0;
	while (cnt < n)
	{
		str_dst[cnt] = str_src[cnt];
		if (str_dst[cnt] == (unsigned char)c)
			return ((void*)(str_dst + cnt + 1));
		cnt++;
	}
	return (NULL);
}
