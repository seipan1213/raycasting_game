/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 14:33:56 by sehattor          #+#    #+#             */
/*   Updated: 2020/10/09 20:47:19 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	cnt;
	int		i;

	cnt = 0;
	if (needle[cnt] == '\0')
		return (char*)(haystack);
	while (haystack[cnt] != '\0' && cnt < len)
	{
		i = 0;
		while (needle[i] == haystack[cnt + i] && cnt + i < len)
		{
			i++;
			if (needle[i] == '\0')
				return (char*)(haystack + cnt);
		}
		cnt++;
	}
	return (NULL);
}
