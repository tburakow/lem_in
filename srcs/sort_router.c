/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_router.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:20:55 by lasalmi           #+#    #+#             */
/*   Updated: 2022/10/10 15:26:31 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void	swap_paths(t_path2 *path1, t_path2 *path2)
{
	t_path2	temp;

	ft_memcpy(&temp, path1, sizeof(t_path2));
	ft_memcpy(path1, path2, sizeof(t_path2));
	ft_memcpy(path2, &temp, sizeof(t_path2));
}

void	sort_router(t_router *router)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = i + 1;
	while (i < router->used - 1)
	{
		while (j < router->used)
		{
			if (router->paths[j].used < router->paths[i].used)
				swap_paths(&router->paths[j], &router->paths[i]);
			j++;
		}
		i++;
		j = i + 1;
	}
}
