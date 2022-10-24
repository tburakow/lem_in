/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_conv_di.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:39:53 by lasalmi           #+#    #+#             */
/*   Updated: 2022/05/27 11:58:06 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_conv_di(long long nb, int zeroprec, size_t intlen, char *str)
{
	static const char	table[] = "0123456789abcdef";

	if (nb < 0)
		nb *= -1;
	str[intlen--] = '\0';
	if ((unsigned long long)nb == -9223372036854775808ULL)
	{
		nb = 922337203685477580;
		str[intlen--] = '8';
	}
	if (nb == 0 && !zeroprec)
		str[intlen] = '0';
	while (nb > 0)
	{
		str[intlen] = table[nb % 10];
		nb /= 10;
		intlen--;
	}
}
