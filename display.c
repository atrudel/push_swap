/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 18:41:48 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/03 19:15:27 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(char *message, t_stack *a, t_stack *b, t_list *moves)
{
	destroy_stack(&a);
	destroy_stack(&b);
	ft_lstdel(&moves, NULL);
	ft_putendl_fd(message, 2);
	exit(-1);
}

void	print_stacks(t_stack *a, t_stack *b, t_options *options)
{
	int	i;
	int	length_a;
	int	length_b;
	int	n;

	length_a = stack_length(a);
	length_b = stack_length(b);
	n = MAX(length_a, length_b);
	i = 0;
	while (++i <= n)
	{
		if (i + length_a > n)
			ft_printf("%s%3d   \t\t",
				options->c ? get_ith_stack(a, i + length_a - n)->color : WHITE,
				get_ith_stack(a, i + length_a - n)->value);
		else
			ft_printf("       \t\t");
		if (i + length_b > n)
			ft_printf("%s%3d",
				options->c ? get_ith_stack(b, i + length_b - n)->color : WHITE,
				get_ith_stack(b, i + length_b - n)->value);
		ft_printf("\n");
	}
	ft_printf(WHITE"_______\t\t_______\nStack a\t\tStack b\n\n");
}

void	print_list_moves(t_list *moves, int fd)
{
	int							i;
	int							j;
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

	i = ft_lstsize(moves) + 1;
	while (--i > 0)
	{
		j = -1;
		while (++j < 11)
			if (instructions[j].f == ft_lstindex(moves, i)->content)
				ft_putendl_fd(instructions[j].command, fd);
	}
}
