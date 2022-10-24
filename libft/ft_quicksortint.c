/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksortint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:20:53 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/11 17:24:42 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	partition(int *arr, int low, int high)
{
	int	i;
	int	j;
	int	pivot;

	i = low;
	j = low;
	pivot = arr[high];
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			ft_swap(&arr[j], &arr[i]);
			i++;
		}
		j++;
	}
	ft_swap(&arr[i], &arr[high]);
	return (i);
}

static void	quicksort_recursion(int *arr, int low, int high)
{
	int	pivot_index;

	if (low > high)
		return ;
	pivot_index = partition(arr, low, high);
	quicksort_recursion(arr, low, pivot_index - 1);
	quicksort_recursion(arr, pivot_index + 1, high);
}

void	ft_quicksortint(int *arr, int len)
{
	quicksort_recursion(arr, 0, len - 1);
}
