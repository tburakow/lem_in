/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_read_length.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:06:43 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/03 00:03:48 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Sets length to len and moves the strdata pointer forward the amount needed*/
static void	ft_pf_set_length(t_strdata *strdata, t_length len, int size)
{
	strdata->flags.length = len;
	strdata->working_format += size;
}

void	ft_pf_read_length(t_strdata *strdata)
{
	if (ft_strnequ(strdata->working_format, "hh", 2))
		ft_pf_set_length(strdata, PF_HH, 2);
	if (ft_strnequ(strdata->working_format, "ll", 2))
		ft_pf_set_length(strdata, PF_LL, 2);
	if (ft_strnequ(strdata->working_format, "h", 1))
		ft_pf_set_length(strdata, PF_H, 1);
	if (ft_strnequ(strdata->working_format, "l", 1))
		ft_pf_set_length(strdata, PF_L, 1);
	if (ft_strnequ(strdata->working_format, "L", 1))
		ft_pf_set_length(strdata, PF_LONGD, 1);
	return ;
}
