/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_queue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 10:48:52 by lasalmi           #+#    #+#             */
/*   Updated: 2022/10/11 13:25:26 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

t_visit	get_visit(t_edge *to_child, t_node *parent, t_visit *current)
{
	t_visit	ret;

	ret.child = to_child->room;
	ret.to_child = to_child;
	ret.parent = parent;
	ret.parent_visit = current;
	return (ret);
}

t_visit	set_start_visit(t_node *node)
{
	t_visit	ret;

	ret.child = node;
	ret.to_child = &(node - 1)->edges.edges[0];
	ret.parent = (node - 1)->edges.edges[0].room;
	ret.parent->visited = 1;
	return (ret);
}

int	handle_edge(t_que *que, t_visit *visit, int i, t_node *end)
{
	t_edges	*edges;
	t_node	*parent;

	edges = &visit->child->edges;
	parent = visit->child;
	que->visits[que->amount] = get_visit(&edges->edges[i], \
	parent, visit);
	edges->edges[i].room->visited = 1;
	if (que->visits[que->amount].child == end)
		return (1);
	que->amount += 1;
	return (0);
}

int	add_visits_from_visit(t_visit *visit, t_que *que, t_node *end, int reverse)
{
	t_edges	*edges;
	t_node	*parent;
	int		i;

	edges = &visit->child->edges;
	parent = visit->child;
	i = 0;
	if (reverse)
		i = edges->used - 1;
	while (i >= 0 && i < (int)edges->used)
	{
		if (edges->edges[i].capacity && !edges->edges[i].room->visited)
		{
			if (handle_edge(que, visit, i, end))
				return (1);
		}
		if (reverse)
			i--;
		else
			i++;
	}
	que->visits[que->amount].child = NULL;
	return (0);
}

t_que	get_visits_until_end(t_data *data, int reverse)
{
	t_visit	*all_visits;
	t_que	que;
	int		ret;
	t_node	*end;

	end = &data->map.nodes[data->end];
	initialize_que(&que);
	all_visits = (t_visit *)malloc(sizeof(t_visit) * MAX_WIDTH);
	if (!all_visits)
		error_and_exit("Memory allocation failed", 17);
	que.visits = all_visits;
	ret = 0;
	que.visits[que.i] = set_start_visit(&data->map.nodes[data->start + 1]);
	while (que.i < que.amount)
	{
		ret = add_visits_from_visit(&que.visits[que.i], &que, end, reverse);
		if (ret)
			return (que);
		que.i++;
	}
	return (que);
}
