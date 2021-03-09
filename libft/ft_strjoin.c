/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:46:43 by sehattor          #+#    #+#             */
/*   Updated: 2020/10/11 21:39:06 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	if (!(str = (char*)malloc((i + j) * sizeof(char) + 1)))
		return (NULL);
	str[i + j] = '\0';
	len = i;
	while (i--)
		str[i] = s1[i];
	while (j--)
		str[len + j] = s2[j];
	return (str);
}
