/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:23:54 by lasalmi           #+#    #+#             */
/*   Updated: 2021/12/06 15:17:06 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_countstrings(char const *str, char delimeter)
{
	int		i;
	int		counted;
	size_t	result;

	counted = 0;
	i = 0;
	result = 0;
	while (str[i] != '\0')
	{
		while (str[i] != delimeter && str[i] != '\0')
		{
			if (counted == 0)
			{
				result++;
				counted = 1;
			}
			i++;
		}
		counted = 0;
		if (str[i] != '\0')
			i++;
	}
	return (result);
}

static	char	**ft_freeall(char **strarray, int j)
{
	j = j - 1;
	while (j >= 0)
	{
		free(strarray[j]);
		j--;
	}
	free(strarray);
	return (NULL);
}

static	char	*ft_fillstring(char const *str, char delimeter)
{
	int		i;
	size_t	length;
	char	*returnstring;

	i = 0;
	length = 0;
	while (str[i] != delimeter && str[i] != '\0')
	{
		i++;
		length++;
	}
	returnstring = (char *)malloc(length * sizeof(char) + 1);
	if (!returnstring)
		return (NULL);
	i = 0;
	while (str[i] != delimeter && str[i] != '\0')
	{
		returnstring[i] = str[i];
		i++;
	}
	returnstring[i] = '\0';
	return (returnstring);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**strarray;
	size_t	stringcount;
	int		i;
	int		j;

	stringcount = ft_countstrings(s, c);
	strarray = (char **)malloc((stringcount + 1) * sizeof(char *));
	if (!strarray)
		return (NULL);
	i = 0;
	j = 0;
	while (stringcount-- > 0)
	{
		while (s[i] == c)
			i++;
		strarray[j] = ft_fillstring(&s[i], c);
		if (!strarray[j])
			return (ft_freeall(strarray, j));
		while (s[i] != c && s[i] != '\0')
			i++;
		j++;
	}
	strarray[j] = NULL;
	return (strarray);
}
