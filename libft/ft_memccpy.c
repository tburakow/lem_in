/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:25:25 by lasalmi           #+#    #+#             */
/*   Updated: 2021/12/02 12:30:20 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*copysource;
	unsigned char	*copydest;
	int				i;
	unsigned char	cchar;

	cchar = (unsigned char)c;
	copysource = (unsigned char *)src;
	copydest = (unsigned char *)dest;
	i = 0;
	while (n > 0)
	{
		copydest[i] = copysource[i];
		if (copysource[i] == cchar)
			return (&copydest[i + 1]);
		i++;
		n--;
	}
	return (NULL);
}
