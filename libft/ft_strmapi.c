/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 19:52:07 by sehattor          #+#    #+#             */
/*   Updated: 2020/10/12 19:19:42 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		s_len;
	char	*ans;

	s_len = 0;
	while (s[s_len] != '\0')
		s_len++;
	if (!(ans = (char*)malloc((s_len + 1) * sizeof(char))))
		return (NULL);
	ans[s_len] = '\0';
	while (s_len--)
		ans[s_len] = f(s_len, s[s_len]);
	return (ans);
}
