/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:32:43 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/03 13:10:10 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(const char *str)
{
	long	result;
	int		multiplier;

	multiplier = 1;
	result = 0;
	if (*str == '-')
	{
		str++;
		multiplier = -1;
	}
	while (*str)
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (multiplier * result);
}
