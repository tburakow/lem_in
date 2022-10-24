/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_oux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:55:27 by lasalmi           #+#    #+#             */
/*   Updated: 2022/04/14 12:32:28 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_conv_oux(unsigned long long nb, int base, size_t intlen, char *str)
{
	static const char	table[] = "0123456789abcdef";

	if (intlen == 0)
	{
		str[intlen] = '\0';
		return ;
	}
	str[intlen--] = '\0';
	if (nb == 0)
		str[intlen] = '0';
	while (nb > 0)
	{
		str[intlen] = table[nb % base];
		nb /= base;
		intlen--;
	}
}
