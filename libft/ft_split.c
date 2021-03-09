/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 21:00:08 by sehattor          #+#    #+#             */
/*   Updated: 2020/10/12 19:19:19 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_stncpy(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s2[i] != '\0' && i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

static int	ary_sum(char const *s, char c)
{
	int	i;
	int	j;
	int	ary_len;

	i = 0;
	ary_len = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i != j)
			ary_len++;
	}
	return (ary_len);
}

static char	**memfree(int i, char **ans)
{
	while (i--)
		free(ans[i]);
	free(ans);
	return (NULL);
}

static int	skip_c(int *j, const char *s, char c)
{
	int	k;
	int	i;

	i = 0;
	while (s[*j + i] == c)
		i++;
	k = *j + i;
	while (s[*j + i] != c && s[*j + i] != '\0')
		i++;
	*j += i;
	return (k);
}

char		**ft_split(char const *s, char c)
{
	int		ary_len;
	int		i;
	int		j;
	int		k;
	char	**ans;

	if (!s)
		return (NULL);
	ary_len = ary_sum(s, c);
	if (!(ans = (char**)malloc((ary_len + 1) * sizeof(char*))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < ary_len)
	{
		k = skip_c(&j, s, c);
		if (!(ans[i] = (char*)malloc((j - k + 1) * sizeof(char))))
			return (memfree(i, ans));
		ft_stncpy(ans[i++], (char*)(s + k), (j - k));
	}
	ans[i] = NULL;
	return (ans);
}
