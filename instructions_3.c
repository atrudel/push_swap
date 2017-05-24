/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:19:49 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/03 19:19:50 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rra(t_stack **a, t_stack **b)
{
	(void)b;
	return (reverse_rotate(a));
}

int		rrb(t_stack **a, t_stack **b)
{
	(void)a;
	return (reverse_rotate(b));
}

int		rrr(t_stack **a, t_stack **b)
{
	int ret_a;
	int ret_b;

	ret_a = reverse_rotate(a);
	ret_b = reverse_rotate(b);
	return (ret_a || ret_b);
}
