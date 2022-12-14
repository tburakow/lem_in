/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:19:55 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/03 12:21:51 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Swaps the values of two integers */
void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
