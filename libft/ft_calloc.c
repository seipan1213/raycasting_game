/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 20:29:04 by sehattor          #+#    #+#             */
/*   Updated: 2020/10/12 23:29:21 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*memory;
	size_t			len;

	len = size * count;
	if (!(memory = (unsigned char*)malloc(len)))
		return (NULL);
	while (len--)
		memory[len] = 0;
	return (void*)(memory);
}
