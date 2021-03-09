/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:54:37 by sehattor          #+#    #+#             */
/*   Updated: 2020/10/12 23:47:53 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*str_dst;
	const unsigned char	*str_src;
	size_t				i;

	str_dst = (unsigned char*)dst;
	str_src = (const unsigned char*)src;
	i = 0;
	if (!dst && !src)
		return (dst);
	if (dst > src)
	{
		while (len--)
			str_dst[len] = str_src[len];
	}
	else
	{
		while (i < len)
		{
			str_dst[i] = str_src[i];
			i++;
		}
	}
	return (dst);
}
