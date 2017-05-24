/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_iter2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:34:30 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/03 20:04:44 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		set_as_sorted(t_stack *element, void *data)
{
	(void)data;
	element->status = 1;
	element->color = GREEN;
	return (1);
}

int		set_as_unsorted(t_stack *element, void *data)
{
	(void)data;
	element->status = 0;
	element->color = RED;
	return (1);
}

int		is_not_fixed(t_stack *element, void *comparison)
{
	(void)comparison;
	if (element->status)
		return (0);
	else
		return (1);
}

void	stack_sorted_status(t_stack *stack)
{
	int tmp;

	if (stack)
	{
		while (stack->next)
			stack = stack->next;
		tmp = stack->value;
		while (stack->prev)
		{
			if (stack->prev->value > stack->value)
				break ;
			tmp = stack->prev->value;
			stack->status = 1;
			stack = stack->prev;
		}
		if (!stack->prev)
			stack->status = 1;
	}
}
