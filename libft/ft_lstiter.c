/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:15:08 by lasalmi           #+#    #+#             */
/*   Updated: 2021/11/29 19:45:47 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*current;
	t_list	*next;

	current = lst;
	next = lst->next;
	while (current != NULL)
	{
		(*f)(current);
		if (next == NULL)
			break ;
		current = next;
		next = current->next;
	}
}
