/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printout.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:11:27 by tburakow          #+#    #+#             */
/*   Updated: 2022/10/11 13:32:59 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	special_printout(t_data *data)
{
	ssize_t	count;

	count = 1;
	ft_printf("\n");
	while (count <= data->ants)
	{
		ft_printf("L%llu-end", count);
		if (count < data->ants)
			ft_printf(" ");
		count++;
	}
}

static void	printout(t_ant *ant)
{
	static size_t	count = 0;

	if (ant->number == 0)
	{
		ant->number = count + 1;
		count++;
	}
	ft_putchar('L');
	ft_printf("%d", ant->number);
	ft_putchar('-');
	ft_printf("%s", ant->position->name);
}

static void	generate_printout(t_path2 *path, size_t round, int first_path)
{
	size_t	i;
	size_t	j;
	size_t	print_of_path;

	print_of_path = 0;
	i = 0;
	j = 0;
	while ((j <= round || j == 0) && j < path->ants)
	{
		if ((size_t)path->ant_dudes[j].progress < path->used)
		{
			path->ant_dudes[j].position = \
			path->nodes[path->ant_dudes[j].progress];
			path->ant_dudes[j].progress++;
			if (print_of_path > 0 || !first_path)
				ft_printf(" ");
			printout(&path->ant_dudes[j]);
			print_of_path++;
		}
		j++;
	}
}

void	make_moves(t_router *router)
{
	size_t	round;
	size_t	i;

	round = 0;
	i = 0;
	ft_printf("\n");
	while (round < router->moves)
	{
		i = 0;
		while (i < router->used)
		{
			if (!i)
				generate_printout(&router->paths[i], round, 1);
			else
				generate_printout(&router->paths[i], round, 0);
			i++;
		}
		ft_putchar('\n');
		round++;
	}
	free_ants(router);
}
