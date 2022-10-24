/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:24:43 by lasalmi           #+#    #+#             */
/*   Updated: 2021/12/05 16:09:11 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*source;
	char			*destination;
	unsigned int	i;

	source = (char *)src;
	destination = (char *)dest;
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (src < dest)
	{
		while (n > 0)
		{
			destination[n - 1] = source[n - 1];
			n--;
		}
	}
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (destination);
}
