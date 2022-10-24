/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:31:22 by lasalmi           #+#    #+#             */
/*   Updated: 2022/10/10 15:26:31 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int	validate_ants(char **buf, t_data *data)
{
	long long	temp;
	size_t		len;
	char		*buffer;

	buffer = ft_strsep(buf, "\n");
	if (!ft_is_int(buffer))
		return (0);
	len = ft_strlen(buffer);
	if (len > 11)
		return (0);
	temp = ft_atoll(buffer);
	if (temp <= 0 || temp > INT_MAX)
		return (0);
	data->ants = (size_t)ft_atoi(buffer);
	return (1);
}

void	get_ants(char **buf, t_data *data)
{
	if (validate_ants(buf, data))
		return ;
	else
		error_and_exit("Ants line invalid", 7);
}
