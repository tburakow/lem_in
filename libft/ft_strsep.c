/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:48:10 by lasalmi           #+#    #+#             */
/*   Updated: 2021/12/08 15:56:04 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_charcompare(const char c, const char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strsep(char **stringp, const char *delim)
{
	int		i;
	char	*rptr;

	rptr = *stringp;
	i = 0;
	if (*stringp == NULL)
		return (NULL);
	while (stringp[0][i] != '\0' && ft_charcompare(stringp[0][i], delim) == 0)
		i++;
	if (stringp[0][i] == '\0')
		*stringp = NULL;
	else
	{
		stringp[0][i] = '\0';
		*stringp = &stringp[0][i + 1];
	}
	return (rptr);
}
