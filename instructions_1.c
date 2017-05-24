/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 17:25:52 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/02 12:58:58 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		perform_instruction(t_stack **a, t_stack **b, char *instruction)
{
	int							i;
	static const t_instruction	instructions[11] = {
		{"sa", sa},
		{"sb", sb},
		{"ss", ss},
		{"pa", pa},
		{"pb", pb},
		{"ra", ra},
		{"rb", rb},
		{"rr", rr},
		{"rra", rra},
		{"rrb", rrb},
		{"rrr", rrr},
	};

	i = -1;
	while (++i < 11)
	{
		if (ft_strcmp(instruction, instructions[i].command) == 0)
		{
			return (instructions[i].f(a, b));
		}
	}
	ft_putendl_fd("Error", 2);
	return (0);
}

int		perform_print_instruction(t_stack **a, t_stack **b, char *instruction)
{
	ft_putendl(instruction);
	return (perform_instruction(a, b, instruction));
}

int		sa(t_stack **a, t_stack **b)
{
	(void)b;
	return (swap(a));
}

int		sb(t_stack **a, t_stack **b)
{
	(void)a;
	return (swap(b));
}

int		ss(t_stack **a, t_stack **b)
{
	int ret_a;
	int ret_b;

	ret_a = swap(a);
	ret_b = swap(b);
	return (ret_a || ret_b);
}
