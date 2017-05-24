/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:24:55 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/03 19:26:20 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		partition(int *array, int left, int right, int pivot)
{
	int tmp;

	while (left <= right)
	{
		while (array[left] < pivot)
			left++;
		while (array[right] > pivot)
			right--;
		if (left <= right)
		{
			tmp = array[left];
			array[left] = array[right];
			array[right] = tmp;
			left++;
			right--;
		}
	}
	return (left);
}

void	quicksort_array(int *array, int left, int right)
{
	int pivot;
	int wall;

	if (left >= right)
		return ;
	pivot = array[(left + right) / 2];
	wall = partition(array, left, right, pivot);
	quicksort_array(array, left, wall - 1);
	quicksort_array(array, wall, right);
}

int		find_median(t_stack *stack)
{
	int		n;
	int		*array;
	int		i;
	int		median;

	n = section_length(stack);
	if (!(array = (int *)malloc(sizeof(int) * n)))
		error_exit("Malloc failed in function find_median", NULL, NULL, NULL);
	i = 0;
	while (i < n)
	{
		array[i] = stack->value;
		stack = stack->next;
		i++;
	}
	quicksort_array(array, 0, n - 1);
	median = array[n / 2];
	free(array);
	return (median);
}
