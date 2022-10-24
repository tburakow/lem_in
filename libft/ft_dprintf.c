/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 00:16:20 by lasalmi           #+#    #+#             */
/*   Updated: 2022/07/16 09:57:42 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dprintf(int fd, const char *input_format, ...)
{
	t_strdata		strdata;
	t_pf_controller	pf_controller;

	va_start(strdata.list, input_format);
	strdata.working_format = input_format;
	ft_pf_init_pf_controller(&pf_controller);
	ft_pf_init_strdata(&strdata);
	pf_controller.caller = FT_DPRINTF;
	pf_controller.fd = fd;
	while (pf_controller.stage != FT_END)
		ft_pf_dispatcher(&pf_controller, &strdata, pf_controller.stage);
	va_end(strdata.list);
	return (pf_controller.chars_written);
}
