/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:26:07 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/03 00:03:48 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Sets the ignored flags for char to zero */
void	ft_pf_validate_c_flags(t_strdata *strdata)
{
	t_flags	*flags;

	flags = &strdata->flags;
	if (flags->padleft == 1)
		flags->pad_with_zeroes = 0;
	flags->space = 0;
	flags->sign = 0;
}

t_status	ft_pf_handle_char_width(t_strdata *strdata)
{
	t_status	ret;

	ret = OKAY;
	if (strdata->width > strdata->strlen)
	{
		if (strdata->flags.padleft)
			ret = ft_pf_pad_with(strdata, ' ');
		else if (strdata->flags.pad_with_zeroes)
			ret = ft_pf_pad_with(strdata, '0');
		else
			ret = ft_pf_pad_with(strdata, ' ');
	}
	return (ret);
}

void	ft_pf_handle_char(t_pf_controller *pf_controller, t_strdata *strdata)
{
	t_status	ret;

	if (strdata->working_format[-1] == 'c')
	ret = ft_pf_conv_char(strdata, va_arg(strdata->list, int));
	else
	ret = ft_pf_conv_char(strdata, strdata->working_format[-1]);
	if (ret == MALLOCFAIL)
		ft_pf_mallocfail(strdata);
	ret = ft_pf_handle_char_width(strdata);
	if (ret == MALLOCFAIL)
		ft_pf_mallocfail(strdata);
	ft_pf_print(pf_controller, strdata);
}
