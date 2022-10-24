/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 21:02:43 by lasalmi           #+#    #+#             */
/*   Updated: 2022/10/11 12:08:42 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	ft_hash_key(char *str)
{
	unsigned long long	ret;

	ret = 7;
	while (*str)
		ret = 23 * ret + *str++;
	return (ret);
}
