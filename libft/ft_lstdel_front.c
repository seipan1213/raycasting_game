/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 01:25:52 by sehattor          #+#    #+#             */
/*   Updated: 2020/10/12 00:00:37 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_front(t_list **lst)
{
	t_list *w;

	w = *lst;
	*lst = (*lst)->next;
	ft_lstdelone(w, &free);
}