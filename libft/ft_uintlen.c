/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:54:58 by lasalmi           #+#    #+#             */
/*   Updated: 2022/05/12 12:56:30 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_uintlen(unsigned long long nb)
{
	size_t	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}
