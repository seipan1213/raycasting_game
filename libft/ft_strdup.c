/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 20:40:54 by sehattor          #+#    #+#             */
/*   Updated: 2020/10/06 20:46:44 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		s1_len;

	s1_len = 0;
	while (s1[s1_len] != '\0')
		s1_len++;
	if (!(dup = (char*)malloc(s1_len * sizeof(char) + 1)))
		return (NULL);
	dup[s1_len] = '\0';
	while (s1_len--)
		dup[s1_len] = s1[s1_len];
	return (dup);
}
