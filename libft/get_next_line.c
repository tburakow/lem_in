/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 08:06:05 by lasalmi           #+#    #+#             */
/*   Updated: 2022/05/29 09:35:09 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_mstrdup(char **dest, char *src)
{
	size_t	size;

	size = ft_strlen(src);
	*dest = (char *)malloc(sizeof(char) * size + 1);
	if (!*dest)
		return (0);
	ft_strlcpy(*dest, src, (size + 1));
	return (1);
}

static char	*ft_bufcat(char *sptr, char *buf, int total_bytes, int startindex)
{
	char	*rptr;

	rptr = (char *)malloc(total_bytes + 1);
	ft_strcpy(rptr, sptr);
	ft_strcpy(&rptr[startindex], buf);
	return (rptr);
}

static int	ft_returnjoined(char **joined, int fd, char **sptr, char *buf)
{
	int	bytes;
	int	total_bytes;

	bytes = (int)ft_strlen(buf);
	total_bytes = (int)ft_strlen(*sptr) + bytes;
	while (bytes > 0)
	{
		*joined = ft_bufcat(*sptr, buf, total_bytes, total_bytes - bytes);
		if (!*joined)
			return (-1);
		free (*sptr);
		*sptr = *joined;
		if (ft_strchr(buf, '\n'))
			break ;
		bytes = read(fd, buf, BUFF_SIZE);
		total_bytes += bytes;
		buf[bytes] = '\0';
	}
	if (bytes == -1)
		return (-1);
	if (bytes == 0 && joined[0][0] == '\0')
		return (0);
	return (1);
}

static int	ft_readuntilnl(int fd, char **sptr, int *readstatus)
{
	char	*buf;
	int		bytes;
	char	*joined;

	buf = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (!buf)
		return (-1);
	bytes = read(fd, buf, BUFF_SIZE);
	if (bytes == 0 || bytes == -1)
	{
		*readstatus = bytes;
		ft_strdel(&buf);
		return (bytes);
	}
	buf[bytes] = '\0';
	*readstatus = ft_returnjoined(&joined, fd, sptr, buf);
	ft_strdel(&buf);
	if (*readstatus == -1)
		return (-1);
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*ptr[FD_MAX];
	char		*temp;
	int			readstatus;
	int			error;

	error = 0;
	if ((fd < 0 || !line || fd >= FD_MAX) || BUFF_SIZE < 1 || (!ptr[fd] && \
!ft_mstrdup(&ptr[fd], "")))
		return (-1);
	if (!ft_strchr(ptr[fd], '\n'))
		error = ft_readuntilnl(fd, &ptr[fd], &readstatus);
	if (error == -1 || readstatus == -1)
		return (-1);
	temp = ptr[fd];
	if (!ft_mstrdup(line, ft_strsep(&ptr[fd], "\n")))
	{
		ft_strdel(&temp);
		return (-1);
	}
	if (ptr[fd])
		ptr[fd] = ft_strdup(ptr[fd]);
	ft_strdel(&temp);
	if (readstatus == 0 && ptr[fd] == 0 && !**line)
		ft_strdel(line);
	return (!!*line);
}
