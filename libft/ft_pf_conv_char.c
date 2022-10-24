/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_conv_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:46:03 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/03 00:03:48 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_status	ft_pf_conv_char(t_strdata *strdata, int c)
{
	if (strdata->variable_str != NULL)
		return (ERROR);
	strdata->variable_str = (char *)malloc(2);
	if (strdata->variable_str == NULL)
		return (MALLOCFAIL);
	strdata->variable_str[0] = c;
	strdata->variable_str[1] = '\0';
	strdata->strlen = 1;
	return (OKAY);
}
