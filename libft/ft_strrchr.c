/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:38:30 by lasalmi           #+#    #+#             */
/*   Updated: 2021/12/02 12:35:21 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	byte_to_find;

	i = 0;
	byte_to_find = (char)c;
	while (s[i] != '\0')
		i++;
	if (s[i] == byte_to_find)
		return ((char *)&s[i]);
	while (i >= 0)
	{
		if (s[i] == byte_to_find)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
