/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_stages.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:13:18 by lasalmi           #+#    #+#             */
/*   Updated: 2022/07/16 09:55:18 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pf_set_stage_to(t_pf_controller *pf_controller, t_stage to)
{
	pf_controller->stage = to;
}

void	ft_pf_dispatcher(t_pf_controller *pf_controller, t_strdata *strdata, \
int func_index)
{
	static const t_myfunc	funcs[] = {
		ft_read_format,
		ft_pf_read_specifiers,
		ft_pf_handle_char,
		ft_pf_handle_str,
		ft_pf_handle_ptr,
		ft_pf_oux_handler,
		ft_pf_handle_di,
		ft_pf_handle_f,
		ft_write_iterated
	};

	funcs[func_index](pf_controller, strdata);
}
