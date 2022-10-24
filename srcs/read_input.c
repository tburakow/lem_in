/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 20:23:42 by lasalmi           #+#    #+#             */
/*   Updated: 2022/10/10 15:49:55 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

ssize_t	read_input(char **buf)
{
	int		fd;
	ssize_t	bytes;

	fd = 0;
	*buf = (char *)malloc(sizeof(char) * FILE_BUFFER);
	if (!*buf)
		error_and_exit("Failed to allocate memory for buf", 36);
	bytes = read(fd, *buf, FILE_BUFFER);
	if (bytes <= 0)
		error_and_exit("read failed.", 20);
	if (bytes == FILE_BUFFER)
		error_and_exit("Too big file.", 21);
	buf[0][bytes] = '\0';
	write(1, *buf, (size_t)bytes);
	return (bytes);
}
