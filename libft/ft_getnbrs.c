/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 11:35:26 by lasalmi           #+#    #+#             */
/*   Updated: 2022/05/28 12:24:20 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Searches for starting addresses of numbers 
in a given string, and handles the pointers like 
strsep NOTE: They need to be delimited. Example "-1-1" doesnt
work */
static int	isnumber(char *str)
{
	if (*str == '-' || *str == '+')
		return (ft_isdigit(*++str));
	return (ft_isdigit(*str));
}

static void	skipnbr(char **str)
{
	while (isnumber(*str))
		(*str)++;
}

char	*ft_getnbrs(char **str)
{
	char	*ret;

	ret = NULL;
	while (**str)
	{
		if (isnumber(*str))
		{
			ret = *str;
			skipnbr(str);
			if (!(**str))
				return (ret);
			(**str) = '\0';
			(*str)++;
			return (ret);
		}
		(*str)++;
	}
	return (ret);
}
