/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 23:09:35 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/06 00:44:40 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	load_file(char ***table, char *file, char *delim)
{
	char	*line;
	int		ret;
	int		fd;
	size_t	i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(2);
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret < 1)
			break ;
		table[i] = ft_line_split(line, delim);
		ft_strdel(&line);
		i++;
	}
	table[i] = NULL;
	close(fd);
	if (ret < 0)
		exit(2);
}

char	***ft_file_split(char *file, char *delim)
{
	int		rows;
	char	***table;

	rows = ft_file_rows(file);
	if (rows < 0)
		exit(2);
	table = (char ***)malloc(sizeof(char **) * rows + 1);
	if (!table)
		exit(2);
	load_file(table, file, delim);
	return (table);
}
