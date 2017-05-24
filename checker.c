/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 12:01:24 by atrudel           #+#    #+#             */
/*   Updated: 2017/04/24 13:38:36 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_options(int argc, char **argv, t_options *options)
{
	int i;

	ft_bzero(options, sizeof(*options));
	i = 0;
	while (i + 1 < argc &&
			ft_strequ_mult(argv[i + 1], 5, "-f", "-c", "-v", "-cv", "-vc"))
	{
		if (ft_strequ(argv[i + 1], "-f"))
		{
			if ((options->fd = open(argv[i + 2], O_RDONLY)) < 0)
			{
				perror(0);
				exit(1);
			}
			i++;
		}
		if (ft_strequ_mult(argv[i + 1], 3, "-v", "-cv", "-vc"))
			options->v = 1;
		if (ft_strequ_mult(argv[i + 1], 3, "-c", "-vc", "-cv"))
			options->c = 1;
		i++;
	}
	options->arg_index = i;
}

void	read_instructions(t_stack **a, t_stack **b, t_options *options)
{
	char		*instruction;
	char		prompt[1];

	if (options->v)
		print_stacks(*a, *b, options);
	while (get_next_line(options->fd, &instruction) > 0)
	{
		if (options->fd && options->v)
		{
			ft_printf(YELLOW"Press 'enter' to move to the next step\n"DEF);
			if (read(0, prompt, 1) < 0)
				error_exit("Error in reading during prompt", *a, *b, NULL);
		}
		options->count++;
		if (!options->v)
			perform_instruction(a, b, instruction);
		else
		{
			perform_print_instruction(a, b, instruction);
			ft_putendl(DEF);
			print_stacks(*a, *b, options);
		}
		ft_strdel(&instruction);
	}
	ft_strdel(&instruction);
}

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_options	options;

	b = NULL;
	set_options(argc, argv, &options);
	if (!(a = parse(argc - options.arg_index, argv + options.arg_index)))
		return (0);
	read_instructions(&a, &b, &options);
	if (stack_is_sorted(a) && stack_length(b) == 0)
	{
		if (options.v)
			ft_printf(B_GREEN"Stack was sorted with %d instructions\n"DEF,
				options.count);
		ft_putendl("OK");
	}
	else
		ft_putendl("KO");
	if (options.fd)
		if (close(options.fd) < 0)
			perror(0);
	destroy_stack(&a);
	destroy_stack(&b);
	return (0);
}
