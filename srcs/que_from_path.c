/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   que_from_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:14:00 by lasalmi           #+#    #+#             */
/*   Updated: 2022/10/11 13:28:28 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

t_edge	*find_edge_to(t_edges *edges, t_node *to)
{
	size_t	i;

	i = 1;
	while (i < edges->used)
	{
		if (edges->edges[i].room == to)
			return (&edges->edges[i]);
		i++;
	}
	return (NULL);
}

int	generate_visit(t_que *que, size_t i, t_path2 *path)
{
	t_edge	*to;
	t_edges	*from_edges;
	t_node	*from;

	from = que->visits[que->amount - 1].child;
	from_edges = &from->edges;
	to = find_edge_to(from_edges, path->nodes[i]);
	que->visits[que->amount] = get_visit(to, from, \
	&que->visits[que->amount - 1]);
	que->amount++;
	if (i == path->used - 1)
		return (0);
	from = que->visits[que->amount - 1].child;
	que->visits[que->amount] = get_visit(&from->edges.edges[0], \
	from, &que->visits[que->amount -1]);
	que->amount++;
	return (1);
}

t_que	generate_visits_from_path(t_data *data, t_path2 *path)
{
	t_que	que;
	size_t	i;

	i = 0;
	initialize_que(&que);
	que.visits = (t_visit *)malloc(sizeof(t_visit) * MAX_WIDTH);
	if (!que.visits)
		error_and_exit("Memory allocation failed", 18);
	que.visits[que.i] = set_start_visit(&data->map.nodes[data->start + 1]);
	while (i < path->used)
	{
		if (!generate_visit(&que, i, path))
			break ;
		i++;
	}
	que.visits[que.amount].child = NULL;
	que.amount -= 1;
	return (que);
}

void	reroute_paths(t_router *router, t_data *data, int reverse)
{
	size_t	i;
	t_que	que;
	t_node	*start_out;
	t_node	*end_in;

	start_out = &data->map.nodes[data->start + 1];
	end_in = &data->map.nodes[data->end];
	i = 0;
	while (i < router->used)
	{
		que = generate_visits_from_path(data, &router->paths[i]);
		if (!traverse_que(&que, start_out))
			error_and_exit("Internal error", 19);
		clear_que(&que);
		que = get_visits_until_end(data, reverse);
		if (!traverse_que(&que, start_out))
			error_and_exit("Internal error", 20);
		clear_que(&que);
		free_router(router);
		*router = get_router(start_out, end_in);
		sort_router(router);
		i++;
	}
	free_router(router);
	*router = get_router(start_out, end_in);
}
