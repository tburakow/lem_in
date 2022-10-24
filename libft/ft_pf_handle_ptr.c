/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:38:32 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/03 00:03:48 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_pf_check_hexa_flags(t_strdata *strdata)
{
	if (strdata->precision > 0 || strdata->flags.padleft == 1)
		strdata->flags.pad_with_zeroes = 0;
	if (strdata->working_format[-1] == 'p')
		strdata->flags.alt_form = 1;
}

void	ft_pf_handle_ptr(t_pf_controller *pf_controller, t_strdata *strdata)
{
	t_status	ret;

	ft_pf_check_hexa_flags(strdata);
	ret = ft_pf_convert_hexa(strdata, va_arg(strdata->list, long long));
	if (ret == MALLOCFAIL)
		ft_pf_mallocfail(strdata);
	if (strdata->strlen < strdata->width && strdata->flags.pad_with_zeroes == 0)
		ft_pf_pad_with(strdata, ' ');
	ft_pf_print(pf_controller, strdata);
}
