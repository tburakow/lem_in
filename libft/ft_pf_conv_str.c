/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_conv_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:05:32 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/03 00:03:48 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_pf_str_precision(t_strdata *strdata, char *str)
{
	size_t	i;
	size_t	strlen;

	strlen = strdata->precision;
	i = 0;
	strdata->variable_str = (char *)malloc(strlen + 1);
	if (!strdata->variable_str)
		ft_pf_mallocfail(strdata);
	while (i < strdata->precision)
	{
		strdata->variable_str[i] = str[i];
		i++;
	}
	strdata->variable_str[i] = '\0';
	strdata->strlen = strdata->precision;
}

t_status	ft_pf_conv_str(t_strdata *strdata, char *str)
{
	size_t				strlen;
	t_status			ret;
	static const char	null_str[] = "(null)";

	ret = OKAY;
	if (!str)
		str = (char *)null_str;
	strlen = ft_strlen(str);
	if ((!strdata->precision && !strdata->explicit_zeroprec) \
	|| strlen < strdata->precision)
	{
		strlen = ft_strlen(str);
		strdata->strlen = strlen;
		strdata->variable_str = ft_strdup(str);
	}
	else
		ft_pf_str_precision(strdata, str);
	if (!strdata->variable_str)
		ret = MALLOCFAIL;
	return (ret);
}
