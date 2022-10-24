/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_edges.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:29:16 by lasalmi           #+#    #+#             */
/*   Updated: 2022/10/11 12:53:00 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static int	add_edge_to_from(t_node *from, t_node *to)
{
	t_node	*from_out;
	int		ret;

	from_out = from->edges.edges[0].room;
	if (!from || !to)
		return (-1);
	ret = add_node_to_edges(&from_out->edges, to, 1);
	if (ret < 0)
		return (ret);
	ret = add_node_to_edges(&to->edges, from_out, 0);
	if (ret < 0)
		return (ret);
	return (1);
}

static int	add_all_edges_between_nodes(t_node *from, t_node *to)
{
	int	ret;

	ret = add_edge_to_from(from, to);
	if (ret < 0)
		return (ret);
	ret = add_edge_to_from(to, from);
	if (ret < 0)
		return (ret);
	return (1);
}

int	handle_edge_line(char **buf)
{
	char	*edge_one_name;
	char	*edge_two_name;
	t_node	*edge_one;
	t_node	*edge_two;

	if (!*buf || !**buf)
		return (0);
	if (**buf == '#')
		return (2);
	edge_one_name = ft_strsep(buf, "-");
	edge_two_name = ft_strsep(buf, "\n");
	if (!edge_one_name || !edge_two_name)
		return (-1);
	edge_one = ft_hash_search(edge_one_name);
	edge_two = ft_hash_search(edge_two_name);
	if (!edge_one || !edge_two)
		error_and_exit("Edge line room doesnt exist!", 6);
	return (add_all_edges_between_nodes(edge_one, edge_two));
}

void	load_edges(t_data *data)
{
	int		ret;

	while (1)
	{
		ret = handle_edge_line(&data->file.buf);
		if (ret == 2)
			go_to_next_line(&data->file.buf);
		if (ret < 0)
			error_and_exit("Faulty edge line", 3);
		if (!ret)
			break ;
	}
}
