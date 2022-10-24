/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:27:01 by lasalmi           #+#    #+#             */
/*   Updated: 2022/07/16 09:57:25 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Reads through the format string, if no output, sets the stage to end*/

void	ft_read_format(t_pf_controller *pf_controller, t_strdata *strdata)
{
	int			*i;
	t_status	ret;

	i = &pf_controller->format_i;
	ret = ft_check_character(strdata->working_format[*i]);
	while (ret == OKAY)
	{
		*i += 1;
		ret = ft_check_character(strdata->working_format[*i]);
		if (ret == NULLBYTE || ret == PERCENT)
		{
			ft_pf_set_stage_to(pf_controller, FT_WRITE);
			return ;
		}
	}
	if (ret == NULLBYTE)
		ft_pf_set_stage_to(pf_controller, FT_END);
	else
		ft_pf_set_stage_to(pf_controller, FT_READ_SPEC);
}

/* Moves pointer forward and adds format_i to chars written and 
changes format_i to zero */
void	ft_pf_increase_written(t_pf_controller *pf_controller, \
t_strdata *strdata)
{
	strdata->working_format += pf_controller->format_i;
	pf_controller->chars_written += pf_controller->format_i;
	pf_controller->format_i = 0;
}

void	ft_write_iterated(t_pf_controller \
*pf_controller, t_strdata *strdata)
{
	t_status	ret;
	int			wret;
	int			fd;

	fd = pf_controller->fd;
	wret = ft_pf_writer(pf_controller, strdata->working_format \
	, pf_controller->format_i);
	if (wret < 0 && ft_output_error(pf_controller, strdata))
		return ;
	ft_pf_increase_written(pf_controller, strdata);
	ret = ft_check_character(strdata->working_format[0]);
	if (ret == OKAY)
		exit(1);
	if (ret == NULLBYTE)
		ft_pf_set_stage_to(pf_controller, FT_END);
	else
		ft_pf_set_stage_to(pf_controller, FT_READ_SPEC);
}

t_status	ft_check_character(const char c)
{
	if (c == '\0')
		return (NULLBYTE);
	if (c == '%')
		return (PERCENT);
	return (OKAY);
}

int	ft_printf(const char *input_format, ...)
{
	t_strdata		strdata;
	t_status		ret;
	t_pf_controller	pf_controller;

	ret = OKAY;
	va_start(strdata.list, input_format);
	strdata.working_format = input_format;
	ft_pf_init_pf_controller(&pf_controller);
	ft_pf_init_strdata(&strdata);
	pf_controller.caller = FT_PRINTF;
	pf_controller.fd = 1;
	while (pf_controller.stage != FT_END)
		ft_pf_dispatcher(&pf_controller, &strdata, pf_controller.stage);
	va_end(strdata.list);
	return (pf_controller.chars_written);
}
