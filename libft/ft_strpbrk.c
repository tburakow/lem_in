/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:02:36 by lasalmi           #+#    #+#             */
/*   Updated: 2021/12/02 12:46:23 by lasalmi          ###   ########.fr       */
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

char	*ft_strpbrk(const char *s, const char *charset)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (ft_charcompare(s[i], charset) == 1)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
