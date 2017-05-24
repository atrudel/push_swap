/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 18:40:49 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/03 18:41:10 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*bubble_sort_rev_a(t_stack **a, t_stack **b, t_list *moves)
{
	int	i;
	int	max;

	max = stack_length(*a);
	while (!stack_is_sorted(*a))
	{
		i = 1;
		while (!stack_is_sorted(*a) && i < max)
		{
			if (STACK_I(a, 1) > STACK_I(a, 2))
				moves = new_move(a, b, &moves, sa);
			if (!stack_is_sorted(*a))
			{
				moves = new_move(a, b, &moves, rra);
				i++;
			}
		}
		if (!stack_is_sorted(*a))
			moves = new_move(a, b, &moves, rra);
	}
	return (moves);
}
