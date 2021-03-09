/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 01:28:53 by sehattor          #+#    #+#             */
/*   Updated: 2020/10/11 01:40:55 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*w;

	i = 0;
	if (!lst)
		return (i);
	w = lst;
	while (w->next != NULL)
	{
		w = w->next;
		i++;
	}
	return (i + 1);
}
