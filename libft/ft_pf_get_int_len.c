/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_get_int_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 01:05:29 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/03 00:03:48 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_check_sign(t_vardata *vardata, long long nb, t_strdata *strdata)
{
	if (strdata->flags.sign || strdata->flags.space)
	{
		if (nb >= 0)
			vardata->conv_len += 1;
	}
	if (nb < 0)
		vardata->conv_len += 1;
}

void	ft_pf_get_sint_len(t_vardata *vardata, long long nb, t_strdata *strdata)
{
	long long	working_nb;

	working_nb = nb;
	vardata->zero_prec = 0;
	vardata->conv_len = 0;
	vardata->padlen = 0;
	if ((unsigned long long)working_nb == -9223372036854775808ULL)
		working_nb += 1;
	if (working_nb == 0 && !strdata->explicit_zeroprec)
		vardata->conv_len += 1;
	if (working_nb < 0)
		working_nb *= -1;
	while (working_nb > 0)
	{
		working_nb /= 10;
		vardata->conv_len += 1;
	}
	vardata->intlen = vardata->conv_len;
	ft_check_sign(vardata, nb, strdata);
	if (strdata->width > vardata->conv_len)
		vardata->padlen = strdata->width - vardata->conv_len;
	ft_pf_check_zeropadding(vardata, strdata);
}
