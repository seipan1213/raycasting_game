/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 01:29:47 by sehattor          #+#    #+#             */
/*   Updated: 2020/10/13 22:13:54 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*w;

	if (!lst || !f)
		return (NULL);
	if (!(new = ft_lstnew(f(lst->content))))
		return (NULL);
	w = new;
	lst = lst->next;
	while (lst)
	{
		if (!(new = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&w, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&w, new);
	}
	return (w);
}
