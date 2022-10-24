/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:35:13 by lasalmi           #+#    #+#             */
/*   Updated: 2021/12/02 12:36:40 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*link_to_del;

	link_to_del = *alst;
	(*del)(link_to_del->content, link_to_del->content_size);
	if (*alst != link_to_del->next)
		free (*alst);
	*alst = NULL;
}
