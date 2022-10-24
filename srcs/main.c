/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 09:43:07 by lasalmi           #+#    #+#             */
/*   Updated: 2022/10/11 13:28:05 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int	load_specifications(t_data *data)
{
	initialize_data(data);
	if (!data->map.nodes)
		error_and_exit("Memory allocation failed", 15);
	read_input(&data->file.buf);
	data->file.free_ptr = data->file.buf;
	get_ants(&data->file.buf, data);
	load_rooms(data);
	load_edges(data);
	if (is_end_next_to_start(data))
	{
		special_printout(data);
		free_data(data);
		exit(0);
	}
	return (1);
}

void	solver(t_data *data, int reverse)
{
	t_que		que;
	int			ret;
	t_router	routes;

	initialize_que(&que);
	while (1)
	{
		que = get_visits_until_end(data, reverse);
		ret = traverse_que(&que, &data->map.nodes[data->start + 1]);
		clear_que(&que);
		if (ret == 0)
			break ;
		routes = get_router(&data->map.nodes[data->start + 1], \
		&data->map.nodes[data->end]);
		reroute_paths(&routes, data, reverse);
		sort_router(&routes);
		count_cost_in_moves(&routes, data->ants);
		if (routes.moves <= data->router.moves)
		{
			free_router(&data->router);
			data->router = routes;
		}
		else
			free_router(&routes);
	}
}

void	clear_graph(t_data *data)
{
	size_t	i;
	size_t	j;

	j = 1;
	i = 0;
	while (i < data->map.room_count)
	{
		while (j < data->map.nodes[i].edges.used)
		{
			if (i % 2 == 0)
			{
				data->map.nodes[i].edges.edges[0].capacity = 1;
				data->map.nodes[i].edges.edges[j].capacity = 0;
			}
			else
			{
				data->map.nodes[i].edges.edges[0].capacity = 0;
				data->map.nodes[i].edges.edges[j].capacity = 1;
			}
			j++;
		}
		j = 1;
		i++;
	}
}

void	solver_wrapper(t_data *data)
{
	solver(data, 0);
	solver(data, 1);
	clear_graph(data);
	solver(data, 1);
	solver(data, 0);
	clear_graph(data);
	solver(data, 0);
	clear_graph(data);
	solver(data, 1);
	clear_graph(data);
}

int	main(void)
{
	t_data	data;

	load_specifications(&data);
	solver_wrapper(&data);
	if (data.router.moves == INT_MAX)
		error_and_exit("no route", 17);
	distribute_ants(&data);
	make_moves(&data.router);
	free_data(&data);
	return (0);
}
