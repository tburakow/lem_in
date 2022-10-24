/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_rows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 09:45:31 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/06 00:43:04 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Takes in a valid filename and returns
the amount of lines in that file. Passing NULL
is undefined behaviour. In case of any error the
function returns -1, if the file is empty returns 0
and otherwise the number of lines.*/
int	ft_file_rows(char *file)
{
	int		rows;
	int		fd;
	char	*line;
	int		ret;

	rows = 0;
	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	ret = get_next_line(fd, &line);
	ft_strdel(&line);
	if (ret > 0)
		rows++;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		ft_strdel(&line);
		if (ret > 0)
			rows++;
	}
	close (fd);
	return (rows);
}
