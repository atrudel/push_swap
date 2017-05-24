/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 10:55:50 by atrudel           #+#    #+#             */
/*   Updated: 2017/04/25 11:31:04 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int		keyboard(int keycode, t_interface *inter)
{
	if (keycode == 53 || keycode == 12)
	{
		if (inter->fd)
			if (close(inter->fd) < 0)
				perror(0);
		destroy_stack(&inter->a);
		destroy_stack(&inter->b);
		mlx_destroy_image(inter->mlx, inter->img);
		mlx_destroy_window(inter->mlx, inter->win);
		exit(0);
	}
	else if (keycode == 78)
		inter->delay = inter->delay / 2;
	else if (keycode == 69)
		inter->delay = inter->delay ? inter->delay * 2 : 1;
	return (0);
}

void	message(t_interface *inter)
{
	char *string;

	mlx_string_put(inter->mlx, inter->win, 0, 5, 0x00FF0000,
		" Nb instructions: ");
	string = ft_itoa(inter->instruction_count);
	mlx_string_put(inter->mlx, inter->win, 250, 5, 0x00FF0000, string);
	ft_strdel(&string);
	mlx_string_put(inter->mlx, inter->win, 0, 25, 0x00FF0000,
		" Delay (microseconds): ");
	string = ft_itoa(inter->delay);
	mlx_string_put(inter->mlx, inter->win, 250, 25, 0x00FF0000, string);
	ft_strdel(&string);
	if (inter->color == 0x0000FF00)
		mlx_string_put(inter->mlx, inter->win, 500, inter->size_y / 2,
			0x0000FF00, "Sorted !");
}

int		display(void *inter)
{
	char *line;

	img_erase((t_interface *)inter);
	stacks_to_img((t_interface *)inter);
	mlx_put_image_to_window(((t_interface *)inter)->mlx,
							((t_interface *)inter)->win,
							((t_interface *)inter)->img, 0, 0);
	message((t_interface *)inter);
	usleep(((t_interface *)inter)->delay);
	if (get_next_line(((t_interface *)inter)->fd, &line))
	{
		perform_instruction(&(((t_interface *)inter)->a),
			&(((t_interface *)inter)->b), line);
		if (stack_is_sorted(((t_interface *)inter)->a))
			stack_sorted_status(((t_interface *)inter)->a);
		stack_iter(((t_interface *)inter)->b, set_as_unsorted, NULL);
		((t_interface *)inter)->instruction_count++;
	}
	else if (stack_is_sorted(((t_interface *)inter)->a))
		((t_interface *)inter)->color = 0x0000FF00;
	ft_strdel(&line);
	return (0);
}

void	parsing_with_options(int argc, char **argv, t_interface *inter)
{
	if (ft_strequ(argv[1], "-f"))
	{
		if ((inter->fd = open(argv[2], O_RDONLY)) < 0)
		{
			perror(0);
			exit(1);
		}
		argc -= 2;
		argv += 2;
	}
	inter->a = parse(argc, argv);
	if (stack_length(inter->a) > 500)
		error_exit("Visualizer can only handle lists of 500 elements max",
			inter->a, NULL, NULL);
	scale(inter);
}

int		main(int argc, char **argv)
{
	t_interface	inter;

	if (argc < 2)
		return (1);
	ft_bzero(&inter, sizeof(inter));
	parsing_with_options(argc, argv, &inter);
	inter.b = NULL;
	inter.size_y = stack_length(inter.a) * 2 + 100;
	inter.size_x = 1100;
	inter.delay = 1000000;
	inter.color = 0x00FFFFFF;
	inter.mlx = mlx_init();
	inter.win = mlx_new_window(inter.mlx, inter.size_x, inter.size_y,
		"Push_swap Visualizer");
	inter.img = mlx_new_image(inter.mlx, inter.size_x, inter.size_y);
	inter.img_addr = mlx_get_data_addr(inter.img, &inter.bits_per_pixel,
										&inter.size_line, &inter.endian);
	mlx_hook(inter.win, 2, 1L << 0, keyboard, &inter);
	mlx_loop_hook(inter.mlx, display, &inter);
	mlx_loop(inter.mlx);
	return (0);
}
