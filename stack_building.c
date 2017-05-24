/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_building.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:32:58 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/03 19:32:59 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*new_stack(int input)
{
	t_stack	*new;

	if ((new = (t_stack *)malloc(sizeof(t_stack))))
	{
		new->prev = NULL;
		new->next = NULL;
		new->value = input;
		new->status = 0;
		new->color = WHITE;
	}
	else
		error_exit("Malloc failed during stack building", NULL, NULL, NULL);
	return (new);
}

void		destroy_stack(t_stack **stack)
{
	if (stack && *stack)
	{
		destroy_stack(&((*stack)->next));
		free(*stack);
		*stack = NULL;
	}
}

t_stack		*pop(t_stack **stack)
{
	t_stack	*first;

	if (*stack)
	{
		first = *stack;
		if (first->next)
			(first->next)->prev = NULL;
		*stack = first->next;
		first->next = NULL;
		return (first);
	}
	return (NULL);
}

int			push(t_stack **stack, t_stack *element)
{
	if (element)
	{
		if (*stack)
		{
			(*stack)->prev = element;
			element->next = *stack;
		}
		*stack = element;
		return (1);
	}
	return (0);
}
