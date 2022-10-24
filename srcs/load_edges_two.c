/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_edges_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:45:49 by tburakow          #+#    #+#             */
/*   Updated: 2022/10/10 16:46:31 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	reallocate_links(t_edges *from)
{
	void	*temp;
	size_t	size;
	size_t	new_size;

	size = from->slots;
	new_size = size * 3;
	temp = from->edges;
	from->edges = (t_edge *)malloc(sizeof(t_edge) * new_size);
	if (!from->edges)
	{
		free(temp);
		return (-1);
	}
	ft_memcpy(from->edges, temp, sizeof(t_edge) * size);
	free(temp);
	from->slots = new_size;
	return (1);
}

int	add_node_to_edges(t_edges *from, t_node *to, uint8_t capacity)
{
	int	ret;

	ret = 0;
	from->used += 1;
	if (from->used == from->slots)
		ret = reallocate_links(from);
	if (ret < 0)
		return (ret);
	from->edges[from->used - 1].room = to;
	from->edges[from->used - 1].capacity = capacity;
	return (1);
}
