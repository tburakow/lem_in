/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:27:41 by lasalmi           #+#    #+#             */
/*   Updated: 2022/09/17 11:00:27 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_delimeter(char c, char *delim)
{
	while (*delim)
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

static size_t	count_columns(char *str, char *delim)
{
	size_t	ret;

	ret = 0;
	if (!str)
		return (ret);
	while (*str)
	{
		if (is_delimeter(*str, delim))
			ret++;
		str++;
	}
	ret++;
	return (ret);
}

char	**ft_line_split(char *str, char *delim)
{
	char	**table;
	char	*current;
	size_t	i;

	i = 0;
	table = (char **)malloc(sizeof(char *) * (count_columns(str, delim) + 1));
	if (!table)
		exit(2);
	current = ft_strsep(&str, delim);
	while (current)
	{
		table[i] = ft_strdup(current);
		if (!table[i])
			exit(2);
		current = ft_strsep(&str, delim);
		i += 1;
	}
	table[i] = NULL;
	return (table);
}
