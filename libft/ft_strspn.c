/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:17:38 by lasalmi           #+#    #+#             */
/*   Updated: 2021/12/02 12:35:39 by lasalmi          ###   ########.fr       */
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

size_t	ft_strspn(const char *s, const char *charset)
{
	size_t	i;

	i = 0;
	while (ft_charcompare(s[i], charset) == 1 && s[i] != '\0')
		i++;
	return (i);
}
