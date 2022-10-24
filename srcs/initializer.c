/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:29:09 by lasalmi           #+#    #+#             */
/*   Updated: 2022/10/10 16:37:06 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	initialize_edges(t_edges *edges)
{
	edges->edges = (t_edge *)malloc(sizeof(t_edge) * EDGE_BUFF);
	if (!edges->edges)
		error_and_exit("Memory allocation failed", 5);
	edges->slots = EDGE_BUFF;
	edges->used = 0;
}

void	initialize_que(t_que *queue)
{
	queue->visits = NULL;
	queue->i = 0;
	queue->amount = 1;
}

int	initialize_node(t_node *node)
{
	node->name = NULL;
	node->type = 0;
	node->visited = 0;
	(node + 1)->name = NULL;
	(node + 1)->type = 1;
	(node + 1)->visited = 0;
	initialize_edges(&node->edges);
	initialize_edges(&(node + 1)->edges);
	node->edges.edges[0].room = node + 1;
	node->edges.edges[0].capacity = 1;
	node->edges.used += 1;
	(node + 1)->edges.edges[0].room = node;
	(node + 1)->edges.edges[0].capacity = 0;
	(node + 1)->edges.used += 1;
	return (1);
}

int	initialize_map(t_map_data *map)
{
	map->end = -1;
	map->start = -1;
	map->room_count = 0;
	map->nodes = (t_node *)malloc(sizeof(t_node) * ROOM_BUFFER);
	if (!map->nodes)
		return (0);
	return (1);
}

void	initialize_data(t_data *data)
{
	data->ants = 0;
	data->start = -1;
	data->end = -1;
	data->file.buf = NULL;
	data->file.free_ptr = NULL;
	data->router.moves = INT_MAX;
	data->router.slots = 0;
	data->router.used = 0;
	data->router.paths = NULL;
	if (!initialize_map(&data->map))
		error_and_exit("Memory allocation failed", 2);
}
