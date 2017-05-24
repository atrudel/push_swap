/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:18:53 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/03 19:18:54 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		pa(t_stack **a, t_stack **b)
{
	return (push(a, pop(b)));
}

int		pb(t_stack **a, t_stack **b)
{
	return (push(b, pop(a)));
}

int		ra(t_stack **a, t_stack **b)
{
	(void)b;
	return (rotate(a));
}

int		rb(t_stack **a, t_stack **b)
{
	(void)a;
	return (rotate(b));
}

int		rr(t_stack **a, t_stack **b)
{
	int ret_a;
	int ret_b;

	ret_a = rotate(a);
	ret_b = rotate(b);
	return (ret_a || ret_b);
}
