/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:22:27 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/03 21:25:50 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*parse(int argc, char **argv)
{
	t_stack	*a;
	char	**inputs;
	int		j;
	int		input_integer;

	a = NULL;
	while (--argc > 0)
	{
		inputs = ft_strsplit(argv[argc], ' ');
		j = 0;
		while (inputs[j])
			j++;
		while (--j >= 0)
		{
			if (ft_atoi_error(inputs[j], &input_integer) &&
					stack_iter(a, &is_different, &input_integer))
				push(&a, new_stack(input_integer));
			else
				error_exit("Error", a, NULL, NULL);
			ft_strdel(&inputs[j]);
		}
		free(inputs);
	}
	return (a);
}
