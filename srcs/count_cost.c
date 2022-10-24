/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:40:36 by tburakow          #+#    #+#             */
/*   Updated: 2022/10/11 13:26:43 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static	ssize_t	path_total(t_path2 *path)
{
	return (path->ants + path->used - 1);
}

static ssize_t	largest_total_cost(t_router *router)
{
	ssize_t		largest;
	size_t		i;

	largest = 0;
	i = 0;
	while (i < router->used)
	{
		if (path_total(&router->paths[i]) > largest)
			if (router->paths[i].ants > 0)
				largest = path_total(&router->paths[i]);
		i++;
	}
	return (largest);
}

static	ssize_t	check_lowest(t_router *router, ssize_t lowest)
{
	size_t		i;

	i = 0;
	lowest = 10000;
	while (i < router->used)
	{
		if (path_total(&router->paths[i]) < lowest)
			lowest = path_total(&router->paths[i]);
		i++;
	}
	return (lowest);
}

static int	is_path_best(t_pathcomp *comp, t_router *router, ssize_t lowest)
{
	if (path_total(&router->paths[comp->i]) <= \
		path_total(&router->paths[comp->j]) \
		&& path_total(&router->paths[comp->i]) <= lowest)
		return (1);
	return (0);
}

void	count_cost_in_moves(t_router *router, ssize_t ants)
{
	t_pathcomp	comp;
	ssize_t		lowest;

	if (router->used == 0)
		return ;
	lowest = 10000;
	pathcomp_set(&comp, 0, 1, router->used);
	router->moves = 0;
	reset_ants(router);
	while (ants)
	{
		lowest = check_lowest(router, lowest);
		if (is_path_best(&comp, router, lowest))
		{
			router->paths[comp.i].ants++;
			ants--;
			pathcomp_set(&comp, 0, 1, router->used);
		}
		else
			pathcomp_set(&comp, comp.i + 1, comp.j + 1, router->used);
	}
	router->moves = largest_total_cost(router);
}
