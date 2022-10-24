/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:07:01 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/03 00:03:48 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_pf_check_f_flags(t_strdata *strdata)
{
	if (strdata->flags.padleft == 1)
		strdata->flags.pad_with_zeroes = 0;
	if (strdata->flags.sign)
		strdata->flags.space = 0;
	if (strdata->precision == 0 && !strdata->explicit_zeroprec)
		strdata->precision = 6;
}

static void	ft_pf_f_prefix(char **ptr, t_strdata *strdata, long double nb)
{
	t_flags	*flags;

	flags = &strdata->flags;
	if ((flags->sign && (1 / nb > 0)) || (flags->sign && nb == 1.0 / 0.0))
		*(*ptr)++ = '+';
	else if ((flags->space && (1 / nb > 0)) || \
	(flags->space && nb == 1.0 / 0.0))
		*(*ptr)++ = ' ';
	else if ((1 / nb) < 0 || nb == -1.0 / 0.0)
		*(*ptr)++ = '-';
}

static long double	ft_pf_fetch_f_var(t_strdata *strdata)
{
	t_length	len;

	len = strdata->flags.length;
	if (len == PF_LONGD)
		return ((long double)va_arg(strdata->list, long double));
	else
		return ((long double)va_arg(strdata->list, double));
}

void	ft_pf_handle_f(t_pf_controller *pf_controller, t_strdata *strdata)
{
	t_vardata	vardata;
	long double	var;
	char		*ptr;

	var = ft_pf_fetch_f_var(strdata);
	ft_pf_check_f_flags(strdata);
	ft_pf_get_double_len(&vardata, var, strdata);
	strdata->variable_str = (char *)malloc(vardata.conv_len + 1);
	if (!strdata->variable_str)
		ft_pf_mallocfail(strdata);
	strdata->strlen = vardata.conv_len;
	ptr = strdata->variable_str;
	ft_pf_f_prefix(&ptr, strdata, var);
	if (strdata->flags.pad_with_zeroes == 1)
		ft_add_zeropad(&ptr, vardata.padlen);
	ft_pf_conv_f(&vardata, strdata, var, ptr);
	if (!strdata->flags.pad_with_zeroes && vardata.padlen)
		ft_pf_uox_padding(strdata, vardata);
	ft_pf_print(pf_controller, strdata);
}
