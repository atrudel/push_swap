/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:16:34 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/03 19:18:11 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*do_swaps(t_stack **a, t_stack **b, t_list *moves)
{
	if ((a && *a && (*a)->next && STACK_I(a, 1) > STACK_I(a, 2)) &&
		(b && *b && (*b)->next && STACK_I(b, 1) < STACK_I(b, 2)))
		moves = new_move(a, b, &moves, ss);
	else if (a && *a && (*a)->next && STACK_I(a, 1) > STACK_I(a, 2))
		moves = new_move(a, b, &moves, sa);
	else if (b && *b && (*b)->next && STACK_I(b, 1) < STACK_I(b, 2))
		moves = new_move(a, b, &moves, sb);
	return (moves);
}

t_list	*sort_a(t_stack **a, t_stack **b, t_list *next_moves)
{
	while ((*a)->status == 10)
		next_moves = new_move(a, b, &next_moves, pb);
	if (stack_length(*a) == 3)
		next_moves = bubble_sort_rev_a(a, b, next_moves);
	else if (section_length(*a) == 2)
		next_moves = do_swaps(a, NULL, next_moves);
	else
		next_moves = divide_a_to_b(a, b, next_moves);
	return (next_moves);
}

t_list	*sort_b(t_stack **a, t_stack **b, t_list *next_moves)
{
	while ((*b)->status == 10)
		next_moves = new_move(a, b, &next_moves, pa);
	if (section_length(*b) == 2)
	{
		next_moves = do_swaps(NULL, b, next_moves);
		next_moves = new_move(a, b, &next_moves, pa);
		next_moves = new_move(a, b, &next_moves, pa);
	}
	else
		next_moves = divide_b_to_a(a, b, next_moves);
	return (next_moves);
}

t_list	*sort(t_stack **a, t_stack **b, t_list *moves, t_options *options)
{
	t_list	*next_moves;
	char	prompt[1];

	next_moves = NULL;
	if (!stack_is_sorted(*a))
		next_moves = sort_a(a, b, next_moves);
	else
	{
		stack_iter(*a, set_as_sorted, NULL);
		if (!(*b))
			return (moves);
		else
			next_moves = sort_b(a, b, next_moves);
	}
	next_moves = trim_list_moves(&next_moves);
	if (options->v)
	{
		if (read(0, prompt, 1) < 0)
			error_exit("Reading error during prompt", *a, *b, moves);
		ft_printf(YELLOW);
		print_list_moves(next_moves, 1);
		ft_printf(DEF"\n");
		print_stacks(*a, *b, options);
	}
	return (sort(a, b, moves = join_lst(next_moves, moves), options));
}
