/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:37:39 by lasalmi           #+#    #+#             */
/*   Updated: 2021/12/02 12:29:35 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*current;
	t_list	*lst_current;

	start = (*f)(lst);
	if (lst->next != NULL)
		start->next = (*f)(lst->next);
	else
		return (start);
	current = start->next;
	lst_current = lst->next;
	while (lst_current->next != NULL)
	{
		current->next = (*f)(lst_current->next);
		if (!current->next)
		{
			ft_lstdel(&start, &ft_bzero);
			return (NULL);
		}
		current = current->next;
		lst_current = lst_current->next;
	}
	current->next = NULL;
	return (start);
}
