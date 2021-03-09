/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:00:36 by sehattor          #+#    #+#             */
/*   Updated: 2020/10/12 19:20:17 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

static bool	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (true);
		i++;
	}
	return (false);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		st;
	int		gl;
	int		i;
	char	*dup;

	i = 0;
	while (s1[i] != '\0' && is_set(s1[i], set))
		i++;
	st = i;
	gl = i;
	while (s1[i] != '\0')
	{
		if (!(is_set(s1[i], set)))
			gl = i;
		i++;
	}
	if (!(dup = (char*)malloc((gl - st + 2) * sizeof(char))))
		return (NULL);
	i = -1;
	while (i++ < gl - st)
		dup[i] = s1[st + i];
	dup[i] = '\0';
	return (dup);
}
