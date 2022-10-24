/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:49:44 by lasalmi           #+#    #+#             */
/*   Updated: 2021/12/05 16:07:40 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*returnptr;

	returnptr = ft_strnew(len);
	if (!returnptr)
		return (NULL);
	ft_strncpy(returnptr, &s[start], len);
	return (returnptr);
}
