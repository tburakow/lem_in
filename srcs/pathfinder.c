/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:12:43 by lasalmi           #+#    #+#             */
/*   Updated: 2022/10/10 15:26:31 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	initialize_path(t_path2 *path)
{
	path->used = 0;
	path->nodes = (t_node **)malloc(sizeof(t_node *) * 10);
	path->slots = 10;
	path->ants = 0;
	path->ant_dudes = NULL;
	path->dudecount = 0;
	if (!path->nodes)
		error_and_exit("Memory allocation failed", 19);
}

void	reallocate_path(t_path2 *path)
{
	t_node	**temp;

	temp = path->nodes;
	path->nodes = (t_node **)malloc(sizeof(t_node *) * (path->slots * 3));
	if (!path->nodes)
		error_and_exit("Memory allocation failed.", 18);
	ft_memcpy(path->nodes, temp, sizeof(t_node *) * path->used);
	path->slots *= 3;
	free(temp);
}

void	add_node_to_path(t_path2 *path, t_node *node)
{
	path->nodes[path->used] = node;
	path->used += 1;
	if (path->used == path->slots)
		reallocate_path(path);
}

t_node	*find_closed_edge(t_edges *edges)
{
	size_t	i;

	i = 1;
	while (i < edges->used)
	{
		if (edges->edges[i].capacity == 0)
			return (edges->edges[i].room);
		i++;
	}
	return (NULL);
}

int	find_path(t_node *node_in, t_path2 *path, t_node *end)
{
	t_node	*node_out;
	t_node	*next_in;

	node_out = node_in + 1;
	if (node_in == end)
	{
		add_node_to_path(path, node_in);
		path->nodes[path->used] = NULL;
		return (1);
	}
	add_node_to_path(path, node_in);
	next_in = find_closed_edge(&node_out->edges);
	if (!next_in)
	{
		return (0);
	}
	else
		return (find_path(next_in, path, end));
}
