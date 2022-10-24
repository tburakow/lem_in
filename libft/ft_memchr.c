/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:07:38 by lasalmi           #+#    #+#             */
/*   Updated: 2021/12/02 12:30:27 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	byte_to_look;
	unsigned int	i;

	src = (unsigned char *)s;
	byte_to_look = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (src[i] == byte_to_look)
			return ((void *)&src[i]);
		i++;
	}
	return (NULL);
}
