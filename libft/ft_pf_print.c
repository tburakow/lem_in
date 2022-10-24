/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:05:12 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/03 00:03:48 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Helper function to handle write error */
int	ft_output_error(t_pf_controller *pf_controller, t_strdata *strdata)
{
	pf_controller->chars_written = -1;
	free(strdata->variable_str);
	strdata->variable_str = NULL;
	free(strdata->padding);
	strdata->padding = NULL;
	pf_controller->stage = FT_END;
	return (1);
}

static void	ft_pf_print_padding(t_pf_controller *pf_controller, \
t_strdata *strdata)
{
	int	ret;
	int	fd;

	fd = pf_controller->fd;
	ret = 0;
	if (!strdata->padding || pf_controller->stage == FT_END)
		return ;
	ret = ft_pf_writer(pf_controller, strdata->padding, strdata->padlen);
	if (ret < 0 && ft_output_error(pf_controller, strdata))
		return ;
	pf_controller->chars_written += strdata->padlen;
	strdata->padlen = 0;
	free(strdata->padding);
	strdata->padding = NULL;
}

static void	ft_pf_print_variable(t_pf_controller *pf_controller, \
t_strdata *strdata)
{
	int	ret;
	int	fd;

	fd = pf_controller->fd;
	ret = 0;
	if (!strdata->variable_str || pf_controller->stage == FT_END)
		return ;
	ret = ft_pf_writer(pf_controller, strdata->variable_str, strdata->strlen);
	if (ret < 0 && ft_output_error(pf_controller, strdata))
		return ;
	pf_controller->chars_written += strdata->strlen;
	strdata->strlen = 0;
	free(strdata->variable_str);
	strdata->variable_str = NULL;
}

/* Prints the generated strings, frees the memory and adds written chars */
void	ft_pf_print(t_pf_controller *pf_controller, t_strdata *strdata)
{
	t_flags	*flags;

	flags = &strdata->flags;
	if (flags->padleft)
		ft_pf_print_variable(pf_controller, strdata);
	ft_pf_print_padding(pf_controller, strdata);
	ft_pf_print_variable(pf_controller, strdata);
	if (pf_controller->stage == FT_END)
		return ;
	ft_pf_init_strdata(strdata);
	pf_controller->stage = FT_READ_PRINT;
}
