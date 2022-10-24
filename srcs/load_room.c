/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 18:22:24 by lasalmi           #+#    #+#             */
/*   Updated: 2022/10/11 12:58:39 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	go_to_next_line(char **buf)
{
	if (!*buf)
		return ;
	while (**buf && **buf != '\n')
		(*buf)++;
	if (**buf == '\n')
		(*buf)++;
}

int	detect_room_line_type(char *buf)
{
	if (!buf)
		error_and_exit("Empty line in map file", 8);
	if (*buf == '#')
		return (2);
	if (*buf == '\n' || *buf == 'L')
		return (3);
	while (*buf && *buf != '\n')
	{
		if (*buf == ' ')
			return (1);
		buf++;
	}
	return (0);
}

void	load_room(t_data *data, size_t *i)
{
	char	*first_coord;
	char	*second_coord;
	char	**buffer;
	int		hash_ret;

	buffer = &data->file.buf;
	data->map.nodes[*i].name = ft_strsep(&data->file.buf, " ");
	data->map.nodes[*i + 1].name = data->map.nodes[*i].name;
	if (!data->map.nodes[*i].name)
		error_and_exit("Name of room faulty", 9);
	hash_ret = ft_hash_add(&data->map.nodes[*i], data->map.nodes[*i].name);
	if (hash_ret != 1)
		error_and_exit("Duplicate room name", 10);
	first_coord = ft_strsep(&data->file.buf, " ");
	second_coord = ft_strsep(&data->file.buf, "\n");
	if (!first_coord || !ft_is_int(first_coord))
		error_and_exit("Invalid room coordinate", 11);
	if (!second_coord || !ft_is_int(second_coord))
		error_and_exit("Invalid room coordinate", 12);
	(*i) += 2;
	if ((*i) == ROOM_BUFFER)
		error_and_exit("Graph size not supported\n", 99);
}

void	command_or_comment(t_data *data, size_t *i)
{
	char	*buffer;

	buffer = ft_strsep(&data->file.buf, "\n");
	if (ft_strequ(buffer, "##start"))
	{
		if (data->start != -1)
			error_and_exit("Start being declared twice", 13);
		data->start = *i;
		return ;
	}
	if (ft_strequ(buffer, "##end"))
	{
		if (data->end != -1)
			error_and_exit("End being declared twice", 8);
		data->end = *i;
		return ;
	}
}

/* Validates the room by assuming that the fields
*are delimeted by a space. Space cannot be in the name of the
*room.
*/
void	load_rooms(t_data *data)
{
	size_t	i;
	int		room_type;

	i = 0;
	room_type = detect_room_line_type(data->file.buf);
	while (room_type)
	{
		if (room_type == 1)
		{
			initialize_node(&data->map.nodes[i]);
			load_room(data, &i);
			data->map.room_count = i;
		}
		else if (room_type == 2)
			command_or_comment(data, &i);
		else if (room_type == 3)
			error_and_exit("Invalid line (L or \n)", 14);
		room_type = detect_room_line_type(data->file.buf);
	}
	if (data->start == data->end || data->start < 0 || data->end < 0)
		error_and_exit("Faulty or missing start and end", 15);
}
