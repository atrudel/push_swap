/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_iter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:34:46 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/03 22:33:14 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		stack_iter(t_stack *stack, int (*f)(t_stack *, void *), void *data)
{
	if (stack)
	{
		while (stack)
		{
			if (f(stack, data) == 0)
				return (0);
			stack = stack->next;
		}
		return (1);
	}
	return (-1);
}

int		is_greater_than(t_stack *element, void *comparison)
{
	if (element->value > *((int *)comparison))
		return (1);
	else
		return (0);
}

int		is_lower_than(t_stack *element, void *comparison)
{
	if (element->value < *((int *)comparison))
		return (1);
	else
		return (0);
}

int		is_different(t_stack *element, void *comparison)
{
	if (element->value == *((int *)comparison))
		return (0);
	else
		return (1);
}

int		if_greater_or_equal_update(t_stack *element, void *comparison)
{
	if (element->value >= *((int *)comparison))
	{
		*((int *)comparison) = element->value;
		return (1);
	}
	else
		return (0);
}
