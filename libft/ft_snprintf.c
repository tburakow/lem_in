/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:35:14 by lasalmi           #+#    #+#             */
/*   Updated: 2022/07/16 09:57:58 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_snprintf(char *str, size_t size, const char *input_format, ...)
{
	t_strdata		strdata;
	t_status		ret;
	t_pf_controller	pf_controller;

	ret = OKAY;
	va_start(strdata.list, input_format);
	strdata.working_format = input_format;
	ft_pf_init_pf_controller(&pf_controller);
	ft_pf_init_strdata(&strdata);
	pf_controller.caller = FT_SPRINTF;
	pf_controller.size = size;
	pf_controller.temp_print = str;
	pf_controller.fd = 1;
	while (pf_controller.stage != FT_END)
		ft_pf_dispatcher(&pf_controller, &strdata, pf_controller.stage);
	va_end(strdata.list);
	*pf_controller.temp_print = '\0';
	return (pf_controller.chars_written);
}
