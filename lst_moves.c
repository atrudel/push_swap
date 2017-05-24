/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:21:07 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/03 19:21:09 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*new_move(t_stack **a, t_stack **b, t_list **moves,
		int (*f)(t_stack **a, t_stack **b))
{
	t_list	*new;

	if (f(a, b))
	{
		if (!(new = (t_list *)malloc(sizeof(t_list))))
			error_exit("Malloc failed while making move list", *a, *b, *moves);
		new->next = NULL;
		new->content_size = 0;
		new->content = f;
		ft_lstadd(moves, new);
	}
	return (*moves);
}

t_list	*join_lst(t_list *first, t_list *second)
{
	t_list	*current;

	if (!(first))
		return (second);
	current = first;
	while (current->next)
		current = current->next;
	current->next = second;
	return (first);
}
