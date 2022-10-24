/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_check_zeropadding.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:41:08 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/03 00:03:48 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pf_check_zeropadding(t_vardata *vardata, t_strdata *strdata)
{
	if (strdata->precision > vardata->intlen)
	{
		vardata->zero_prec = (strdata->precision - vardata->intlen);
		vardata->conv_len += vardata->zero_prec;
		if (vardata->conv_len >= strdata->width)
		{
			strdata->padlen = 0;
			vardata->padlen = 0;
		}
	}
	else if (strdata->flags.pad_with_zeroes == 1 && \
strdata->width > vardata->conv_len)
	{
		vardata->zero_prec = vardata->padlen;
		vardata->conv_len += vardata->zero_prec;
		strdata->strlen = vardata->conv_len;
		vardata->padlen = 0;
		strdata->flags.pad_with_zeroes = 0;
	}
}
