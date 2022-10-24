/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:10:20 by tburakow          #+#    #+#             */
/*   Updated: 2022/10/11 13:29:42 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	is_end_next_to_start(t_data *data)
{
	size_t	i;
	t_node	*start;
	t_node	*end;

	i = 0;
	start = &data->map.nodes[data->start + 1];
	end = &data->map.nodes[data->end];
	while (i < start->edges.used)
	{
		if (start->edges.edges[i].room == end)
			return (1);
		i++;
	}
	return (0);
}

/* Sets path indexes to desired values for comparison of two distinct paths. */
void	pathcomp_set(t_pathcomp *comp, size_t i, size_t j, ssize_t max)
{
	comp->i = i;
	if (comp->i >= (size_t)max)
		comp->i = 0;
	comp->j = j;
	if (comp->j >= (size_t)max)
		comp->j = 0;
}

/* This function allocates memory for the ants in each path accordingly,
and sets their values as zero or NULL */
void	distribute_ants(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < data->router.used)
	{
		data->router.paths[i].ant_dudes = (t_ant *)malloc(sizeof(t_ant) \
		* data->router.paths[i].ants);
		if (!data->router.paths[i].ant_dudes)
			error_and_exit("failed to allocate memory for ant_dudes", 35);
		j = 0;
		while (j < data->router.paths[i].ants)
		{
			data->router.paths[i].ant_dudes[j].position = NULL;
			data->router.paths[i].ant_dudes[j].number = 0;
			data->router.paths[i].ant_dudes[j].progress = 0;
			j++;
		}
		i++;
	}
}
