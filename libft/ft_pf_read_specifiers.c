/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_read_specifiers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:26:51 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/03 00:03:48 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pf_validflag(char c)
{
	return (c == '0' || c == '-' || c == '+' || c == ' ' \
	|| c == '#');
}

void	ft_readflags(t_strdata *strdata)
{
	t_flags	*flags;

	flags = &strdata->flags;
	while (ft_pf_validflag(strdata->working_format[0]))
	{
		if (strdata->working_format[0] == ' ')
			flags->space = 1;
		if (strdata->working_format[0] == '+')
			flags->sign = 1;
		if (strdata->working_format[0] == '-')
			flags->padleft = 1;
		if (strdata->working_format[0] == '0')
			flags->pad_with_zeroes = 1;
		if (strdata->working_format[0] == '#')
			flags->alt_form = 1;
		strdata->working_format += 1;
	}
}

void	ft_readprecision(t_strdata *strdata)
{
	int	result;

	result = 0;
	if (strdata->working_format[0] == '.')
	{
		strdata->working_format += 1;
		ft_pf_skip_leading_zeroes(&strdata->working_format);
		if (!ft_isdigit(strdata->working_format[0]) || \
		strdata->working_format[0] == '0')
		{
			strdata->explicit_zeroprec = 1;
			if (ft_isdigit(strdata->working_format[0]))
				strdata->working_format += 1;
			return ;
		}
		while (ft_isdigit(strdata->working_format[0]))
		{
			result = result * 10 + (strdata->working_format[0] - '0');
			strdata->working_format += 1;
		}
		strdata->precision = result;
	}
}

void	ft_readwidth(t_strdata *strdata)
{
	int	result;

	result = 0;
	while (ft_isdigit(strdata->working_format[0]))
	{
		result = result * 10 + (strdata->working_format[0] - '0');
		strdata->working_format += 1;
	}
	strdata->width = result;
}

/* Moves the pointer one byte forward to skip the % and sends the working format
to other functions to read the specifiers and move the pointer further*/
void	ft_pf_read_specifiers(t_pf_controller *pf_controller, \
t_strdata *strdata)
{
	strdata->working_format += 1;
	if (*strdata->working_format == '\0')
	{
		pf_controller->stage = FT_END;
		return ;
	}
	ft_readflags(strdata);
	ft_readwidth(strdata);
	ft_readprecision(strdata);
	ft_pf_read_length(strdata);
	pf_controller->stage = ft_pf_read_conv(strdata);
}
