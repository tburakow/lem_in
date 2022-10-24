/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 21:23:21 by lasalmi           #+#    #+#             */
/*   Updated: 2022/09/11 21:33:49 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_str_arr(char ***arr)
{
	size_t	i;

	i = 0;
	while ((*arr)[i])
	{
		free((*arr)[i]);
		(**arr) = NULL;
		i++;
	}
	free (*arr);
	*arr = NULL;
}
