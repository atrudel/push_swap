/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:23:37 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/03 23:36:15 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_end(t_stack *b)
{
	while (b && b->next)
		b = b->next;
	return (b);
}

t_list	*reset_end_a(t_stack **a, t_stack **b, t_list *moves, t_stack *end)
{
	if (!stack_iter(*a, is_not_fixed, NULL))
		while (end->next)
			moves = new_move(a, b, &moves, rra);
	if (section_length(*a) == 2 || section_length(*b) == 2)
		moves = do_swaps(a, b, moves);
	return (moves);
}

t_list	*reset_end_b(t_stack **a, t_stack **b, t_list *moves, t_stack *end)
{
	if (!stack_iter(*b, is_not_fixed, NULL))
		while (end->next)
			moves = new_move(a, b, &moves, rrb);
	if (section_length(*a) == 2 || section_length(*b) == 2)
		moves = do_swaps(a, b, moves);
	return (moves);
}

t_list	*divide_a_to_b(t_stack **a, t_stack **b, t_list *moves)
{
	int		median;
	t_stack	*end;

	if (*a)
	{
		median = find_median(*a);
		end = get_end(*a);
		while (!stack_iter(*a, is_greater_than, &median))
		{
			if ((*a)->value < median)
				moves = new_move(a, b, &moves, pb);
			else if ((*a)->value > median)
				moves = new_move(a, b, &moves, ra);
			else
			{
				moves = new_move(a, b, &moves, pb);
				moves = new_move(a, b, &moves, rb);
			}
		}
		moves = reset_end_a(a, b, moves, end);
		moves = new_move(a, b, &moves, rrb);
		(*b)->status = 10;
		(*b)->color = RED;
	}
	return (moves);
}

t_list	*divide_b_to_a(t_stack **a, t_stack **b, t_list *moves)
{
	int		median;
	t_stack	*end;

	if (*b)
	{
		end = get_end(*b);
		median = find_median(*b);
		while (!stack_iter(*b, is_lower_than, &median))
		{
			if ((*b)->value > median)
				moves = new_move(a, b, &moves, pa);
			else if ((*b)->value < median)
				moves = new_move(a, b, &moves, rb);
			else
			{
				moves = new_move(a, b, &moves, pa);
				moves = new_move(a, b, &moves, ra);
			}
		}
		moves = reset_end_b(a, b, moves, end);
		moves = new_move(a, b, &moves, rra);
		(*a)->status = 10;
		(*a)->color = RED;
	}
	return (moves);
}
