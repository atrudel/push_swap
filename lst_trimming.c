/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_trimming.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:21:30 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/03 19:22:12 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	substitute_moves(t_list **ptr, int (*f)(t_stack **, t_stack **))
{
	t_list	*new_move;
	t_list	*first;

	first = *ptr;
	if (f)
	{
		new_move = (t_list *)malloc(sizeof(t_list));
		new_move->content = f;
		new_move->next = first->next->next;
		*ptr = new_move;
	}
	else
		*ptr = first->next->next;
	free(first->next);
	free(first);
}

int		redundant_moves(t_list *first, t_list *second)
{
	if (first->content == pa && second->content == pb)
		return (1);
	if (first->content == pb && second->content == pa)
		return (1);
	if (first->content == ra && second->content == rra)
		return (1);
	if (first->content == rra && second->content == ra)
		return (1);
	if (first->content == rb && second->content == rrb)
		return (1);
	if (first->content == rrb && second->content == rb)
		return (1);
	return (0);
}

t_list	*trim_list_moves(t_list **moves)
{
	t_list	**previous;
	t_list	*current;
	t_list	*next;

	previous = moves;
	while (*previous && (*previous)->next)
	{
		current = (*previous);
		next = (*previous)->next;
		if (redundant_moves(current, next))
			substitute_moves(previous, NULL);
		else
			previous = &(current->next);
	}
	return (*moves);
}
