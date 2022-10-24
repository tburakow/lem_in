/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:02:48 by lasalmi           #+#    #+#             */
/*   Updated: 2022/05/20 13:15:50 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	ft_thirdcpy(void *dest, const void *src, size_t *n)
{
	size_t		count;
	size_t		i;
	char		*copysource;
	char		*copydest;

	i = 0;
	count = *n / 1;
	if (!count)
		return ;
	*n %= 1;
	copysource = (char *)src;
	copydest = (char *)dest;
	while (count--)
	{
		copydest[i] = copysource[i];
		i++;
	}
}

static void	ft_secondcpy(void *dest, const void *src, size_t *n)
{
	size_t		count;
	size_t		i;
	uint64_t	*copysource;
	uint64_t	*copydest;

	i = 0;
	count = *n / 8;
	if (!count)
		ft_thirdcpy(dest, src, n);
	*n %= 8;
	copysource = (uint64_t *)src;
	copydest = (uint64_t *)dest;
	while (count--)
	{
		copydest[i] = copysource[i];
		i++;
	}
	ft_thirdcpy(&copydest[i], &copysource[i], n);
}

static void	ft_firstcpy(void *dest, const void *src, size_t *n)
{
	size_t		count;
	size_t		i;
	__uint128_t	*copysource;
	__uint128_t	*copydest;

	i = 0;
	count = *n / 16;
	if (!count)
		ft_secondcpy(dest, src, n);
	*n %= 16;
	copysource = (__uint128_t *)src;
	copydest = (__uint128_t *)dest;
	while (count--)
	{
		copydest[i] = copysource[i];
		i++;
	}
	ft_secondcpy(&copydest[i], &copysource[i], n);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*copysource;
	char	*copydest;
	int		i;

	copysource = (char *)src;
	copydest = (char *)dest;
	i = 0;
	if (!dest && !src)
		return (dest);
	ft_firstcpy(dest, src, &n);
	return (dest);
}
