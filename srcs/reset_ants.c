/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:58:31 by tburakow          #+#    #+#             */
/*   Updated: 2022/10/10 17:01:07 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	reset_ants(t_router *router)
{
	size_t	i;

	i = 0;
	while (i < router->used)
		router->paths[i++].ants = 0;
}
