/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:52:44 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/15 13:53:42 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_abs(int value)
{
	if (value < 0)
		return (value * -1);
	return (value);
}
