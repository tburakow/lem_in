/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_get_uint_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:57:24 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/03 00:03:48 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_measure_altform(t_strdata *strdata, t_vardata *vardata)
{
	if (strdata->working_format[-1] == 'o')
	{
		vardata->conv_len += 1;
		if (strdata->precision > vardata->intlen)
			strdata->precision--;
	}
	else
		vardata->conv_len += 2;
}

int	ft_pf_get_conv_base(t_strdata *strdata)
{
	if (strdata->working_format[-1] == 'x')
		return (16);
	if (strdata->working_format[-1] == 'o')
		return (8);
	if (strdata->working_format[-1] == 'X')
		return (16);
	if (strdata->working_format[-1] == 'u')
		return (10);
	return (10);
}

void	ft_add_zeropad(char **str, size_t padlen)
{
	size_t	i;

	i = 0;
	while (padlen > 0)
	{
		str[0][i] = '0';
		i++;
		padlen--;
	}
	*str += i;
}

void	ft_pf_add_0x(char **str, long long var, t_strdata *strdata)
{
	if (strdata->working_format[-1] != 'o' && var != 0)
	{
		str[0][0] = '0';
		str[0][1] = 'x';
		*str += 2;
		return ;
	}
	if (strdata->working_format[-1] == 'o')
	{
		if (var != 0 || strdata->explicit_zeroprec)
		{
			str[0][0] = '0';
			*str += 1;
			if (var == 0)
				strdata->strlen += 1;
		}
	}
}

void	ft_pf_get_uint_data(t_vardata *vardata, unsigned long long nb, \
int base, t_strdata *strdata)
{
	unsigned long long	backup;

	backup = nb;
	ft_pf_init_vardata(vardata);
	if (nb == 0 && !strdata->explicit_zeroprec)
		vardata->conv_len = 1;
	while (nb > 0)
	{
		nb /= base;
		vardata->conv_len++;
	}
	vardata->intlen = vardata->conv_len;
	if (strdata->flags.alt_form == 1 && backup != 0)
		ft_measure_altform(strdata, vardata);
	if (vardata->conv_len < strdata->width)
		vardata->padlen = (strdata->width - vardata->conv_len);
	ft_pf_check_zeropadding(vardata, strdata);
}
