/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 01:25:16 by sehattor          #+#    #+#             */
/*   Updated: 2020/10/13 22:14:57 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*w;
	t_list	*tmp;

	if (!*lst || !lst)
		return ;
	w = *lst;
	while (w != NULL)
	{
		tmp = w->next;
		ft_lstdelone(w, del);
		w = tmp;
	}
	*lst = NULL;
}
