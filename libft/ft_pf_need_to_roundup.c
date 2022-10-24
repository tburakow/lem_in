/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_need_to_roundup.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:47:00 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/03 00:03:48 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Bankers rounding with previous digit, otherwise to closest */
int	ft_pf_need_upround_d(double d, int precision)
{
	long long	previous;
	long double	remainder;

	remainder = (long double)d;
	if (!precision)
		previous = (long long)d;
	remainder -= (long long)d;
	while (precision--)
	{
		remainder *= 10.0L;
		if (precision == 0)
			previous = (long long)remainder;
		remainder -= (long long)remainder;
	}
	if (remainder > 0.5L || (previous % 2 != 0 && remainder == 0.5))
		return (1);
	return (0);
}

int	ft_pf_need_upround(long double d, int precision, t_strdata *strdata)
{
	long long	previous;
	long double	remainder;

	if (strdata->flags.length != PF_LONGD)
		return (ft_pf_need_upround_d(d, precision));
	remainder = (long double)d;
	if (!precision)
		previous = (long long)d;
	remainder -= (long long)d;
	while (precision--)
	{
		remainder *= 10.0L;
		if (precision == 0)
			previous = (long long)remainder;
		remainder -= (long long)remainder;
	}
	if (remainder > 0.5L || (previous % 2 != 0 && remainder == 0.5))
		return (1);
	return (0);
}
