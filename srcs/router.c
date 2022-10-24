/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   router.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:02:24 by lasalmi           #+#    #+#             */
/*   Updated: 2022/10/10 16:40:45 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	reallocate_router_paths(t_router *router)
{
	t_path2	*temp;

	temp = router->paths;
	router->paths = (t_path2 *)malloc(sizeof(t_path2) * (router->slots * 3));
	if (!router->paths)
		error_and_exit("Memory allocation failed.", 22);
	ft_memcpy(router->paths, temp, sizeof(t_path2) * router->used);
	router->slots *= 3;
	free(temp);
}

void	initialize_router(t_router *router)
{
	router->moves = INT_MAX;
	router->paths = NULL;
	router->paths = (t_path2 *)malloc(sizeof(t_path2) * 10);
	if (!router->paths)
		error_and_exit("Memory allocation failed.", 23);
	router->used = 0;
	router->slots = 10;
}

void	add_path_to_router(t_router *router, t_path2 *path)
{
	router->paths[router->used] = *path;
	router->used += 1;
	if (router->used == router->slots)
		reallocate_router_paths(router);
	path->nodes = NULL;
	initialize_path(path);
}

t_router	get_router(t_node *start_out, t_node *end)
{
	t_router	router;
	t_path2		path;
	size_t		i;

	initialize_router(&router);
	initialize_path(&path);
	i = start_out->edges.used - 1;
	while (i > 0)
	{
		if (!start_out->edges.edges[i].capacity)
		{
			if (find_path(start_out->edges.edges[i].room, &path, end))
				add_path_to_router(&router, &path);
			else
				error_and_exit("Internal error", 24);
		}
		i -= 1;
	}
	if (i == start_out->edges.used || i < 1)
	{
		free(path.nodes);
		path.nodes = NULL;
	}
	return (router);
}
