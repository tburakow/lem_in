/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   que_traverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:24:21 by lasalmi           #+#    #+#             */
/*   Updated: 2022/10/11 13:26:56 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	turn_faucet(t_edge *edge)
{
	if (edge->capacity == 1)
		edge->capacity = 0;
	else
		edge->capacity = 1;
}

t_edge	*find_edge(t_edges *edges, t_node *to_find)
{
	size_t	i;

	i = 0;
	while (i < edges->used)
	{
		if (edges->edges[i].room == to_find)
			return (&edges->edges[i]);
		i++;
	}
	return (NULL);
}

void	clear_que_visited(t_que *que)
{
	size_t	i;

	i = 0;
	while (i <= que->amount && que->visits[i].child)
	{
		que->visits[i].child->visited = 0;
		que->visits[i].parent->visited = 0;
		i++;
	}
}

int	traverse_que(t_que *que, t_node *start_out)
{
	t_visit	*current;

	if (!que->visits[que->amount].child)
		return (0);
	current = &que->visits[que->amount];
	while (1)
	{
		turn_faucet(current->to_child);
		turn_faucet(find_edge(&current->child->edges, current->parent));
		current = current->parent_visit;
		if (current->child == start_out)
			break ;
	}
	return (1);
}
