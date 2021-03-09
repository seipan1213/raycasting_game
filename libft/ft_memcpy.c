/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:30:20 by sehattor          #+#    #+#             */
/*   Updated: 2020/10/12 23:46:36 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*str_dst;
	const unsigned char	*str_src;
	size_t				i;

	str_dst = (unsigned char*)dst;
	str_src = (const unsigned char*)src;
	if (!dst && !src)
		return (dst);
	i = 0;
	while (i < n)
	{
		str_dst[i] = str_src[i];
		i++;
	}
	return (dst);
}
