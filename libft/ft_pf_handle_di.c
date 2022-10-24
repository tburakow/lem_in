/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle_di.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 01:03:15 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/03 00:03:48 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_pf_di_prefix(char **ptr, t_strdata *strdata, long long nb)
{
	t_flags	*flags;

	flags = &strdata->flags;
	if (flags->sign && nb >= 0)
		*(*ptr)++ = '+';
	else if (flags->space && nb >= 0)
		*(*ptr)++ = ' ';
	else if (nb < 0)
		*(*ptr)++ = '-';
}

static unsigned long long	ft_pf_fetch_di_var(t_strdata *strdata)
{
	t_length	len;

	len = strdata->flags.length;
	if (len == PF_H)
		return ((short)va_arg(strdata->list, int));
	if (len == PF_HH)
		return ((signed char)va_arg(strdata->list, int));
	if (len == PF_LL)
		return ((va_arg(strdata->list, long long)));
	if (len == PF_L)
		return ((long long)va_arg(strdata->list, long));
	return ((long long)va_arg(strdata->list, int));
}

static void	ft_pf_check_di_flags(t_strdata *strdata)
{
	if (strdata->precision > 0 || strdata->flags.padleft == 1 \
	|| strdata->explicit_zeroprec)
		strdata->flags.pad_with_zeroes = 0;
	if (strdata->flags.sign)
		strdata->flags.space = 0;
}

void	ft_pf_handle_di(t_pf_controller *pf_controller, t_strdata *strdata)
{
	long long	var;
	t_vardata	vardata;
	char		*ptr;

	var = ft_pf_fetch_di_var(strdata);
	ft_pf_check_di_flags(strdata);
	ft_pf_get_sint_len(&vardata, var, strdata);
	strdata->variable_str = (char *)malloc(vardata.conv_len + 1);
	strdata->strlen = vardata.conv_len;
	if (!strdata->variable_str)
		ft_pf_mallocfail(strdata);
	ptr = strdata->variable_str;
	ft_pf_di_prefix(&ptr, strdata, var);
	if (vardata.zero_prec > 0)
		ft_add_zeropad(&ptr, vardata.zero_prec);
	if (strdata->flags.pad_with_zeroes == 1)
		ft_add_zeropad(&ptr, vardata.padlen);
	ft_conv_di(var, strdata->explicit_zeroprec, vardata.intlen, ptr);
	if (!strdata->flags.pad_with_zeroes && vardata.padlen)
		ft_pf_uox_padding(strdata, vardata);
	ft_pf_print(pf_controller, strdata);
}
