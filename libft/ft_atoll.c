/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:06:36 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/03 13:10:12 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_atoll(const char *str)
{
	long long	result;
	int			multiplier;

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
