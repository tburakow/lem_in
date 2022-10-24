/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:30:58 by lasalmi           #+#    #+#             */
/*   Updated: 2022/10/11 13:11:59 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	free_router(t_router *router)
{
	size_t	i;

	i = 0;
	while (i < router->used)
	{
		free(router->paths[i].nodes);
		i++;
	}
	free(router->paths);
}

void	free_data(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->map.room_count)
		free(data->map.nodes[i++].edges.edges);
	free(data->file.free_ptr);
	free(data->map.nodes);
	free_router(&data->router);
}

void	free_ants(t_router *router)
{
	size_t	i;

	i = 0;
	while (i < router->used)
		free(router->paths[i++].ant_dudes);
}

void	clear_que(t_que *que)
{
	size_t	i;

	i = 0;
	clear_que_visited(que);
	free(que->visits);
	que->visits = NULL;
	que->i = 0;
	que->amount = 0;
}
