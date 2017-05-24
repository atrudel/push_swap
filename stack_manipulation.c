/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:35:57 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/03 19:35:58 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		swap(t_stack **stack)
{
	t_stack *first;
	t_stack *second;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		second = (*stack)->next;
		if (second->next)
			(second->next)->prev = first;
		first->next = second->next;
		first->prev = second;
		second->next = first;
		second->prev = NULL;
		*stack = second;
		return (1);
	}
	return (0);
}

int		rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack *last;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		last = (*stack)->next;
		while (last->next)
			last = last->next;
		*stack = first->next;
		(*stack)->prev = NULL;
		first->next = NULL;
		first->prev = last;
		last->next = first;
		return (1);
	}
	return (0);
}

int		reverse_rotate(t_stack **stack)
{
	t_stack *first;
	t_stack *last;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		last = (*stack)->next;
		while (last->next)
			last = last->next;
		(last->prev)->next = NULL;
		last->prev = NULL;
		last->next = first;
		first->prev = last;
		*stack = last;
		return (1);
	}
	return (0);
}
