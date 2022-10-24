/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:11:34 by lasalmi           #+#    #+#             */
/*   Updated: 2021/12/06 15:15:31 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlink;

	newlink = (t_list *)malloc(sizeof(t_list));
	if (!newlink)
		return (NULL);
	if (content == NULL)
	{
		newlink->content = NULL;
		newlink->content_size = 0;
		newlink->next = NULL;
		return (newlink);
	}
	else
	{
		newlink->content = ft_memalloc(content_size);
		if (!newlink->content)
		{
			free(newlink);
			return (NULL);
		}
		ft_memcpy(newlink->content, content, content_size);
		newlink->content_size = content_size;
		newlink->next = NULL;
		return (newlink);
	}
}
