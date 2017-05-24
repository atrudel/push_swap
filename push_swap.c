/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:23:01 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/03 22:15:47 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_options(int argc, char **argv, t_options *options)
{
	int i;

	ft_bzero(options, sizeof(*options));
	i = 0;
	options->fd = 1;
	while (i + 1 < argc &&
			ft_strequ_mult(argv[i + 1], 5, "-f", "-c", "-v", "-cv", "-vc"))
	{
		if (ft_strequ(argv[i + 1], "-f"))
		{
			if ((options->fd = open(argv[i + 2], O_WRONLY)) < 0)
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

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_list		*moves;
	t_options	options;

	set_options(argc, argv, &options);
	if (!(a = parse(argc - options.arg_index, argv + options.arg_index)))
		return (0);
	b = NULL;
	if (options.v)
	{
		ft_printf(YELLOW"Starting stack: \n"DEF);
		print_stacks(a, b, &options);
	}
	moves = NULL;
	moves = sort(&a, &b, moves, &options);
	moves = trim_list_moves(&moves);
	print_list_moves(moves, options.fd);
	destroy_stack(&a);
	destroy_stack(&b);
	ft_lstdel(&moves, NULL);
	if (options.fd != 1)
		if (close(options.fd) < 0)
			perror(0);
	return (0);
}
