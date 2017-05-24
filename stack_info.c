/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:33:24 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/03 22:40:54 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		stack_is_sorted(t_stack *stack)
{
	int tmp;

	if (stack)
	{
		tmp = stack->value;
		return (stack_iter(stack, &if_greater_or_equal_update, &tmp));
	}
	return (1);
}

int		stack_has_no_doubles(t_stack *stack)
{
	int	ret;
	int comparison;

	if (!stack || !(stack->next))
		return (1);
	comparison = stack->value;
	ret = stack_iter(stack->next, &is_different, &comparison);
	return (ret && stack_has_no_doubles(stack->next));
}

int		section_length(t_stack *stack)
{
	int count;

	count = 0;
	while (stack && stack->status == 10)
		stack = stack->next;
	while (stack && stack->status == 0)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int		stack_length(t_stack *stack)
{
	int count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

t_stack	*get_ith_stack(t_stack *stack, int index)
{
	int i;

	i = 1;
	while (stack && i <= index)
	{
		if (i == index)
			return (stack);
		i++;
		stack = stack->next;
	}
	return (NULL);
}
