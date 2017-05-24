/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 10:55:57 by atrudel           #+#    #+#             */
/*   Updated: 2017/04/29 12:08:27 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	scale(t_interface *inter)
{
	int		min;
	int		max;
	t_stack *current;

	current = inter->a;
	min = current->value;
	max = current->value;
	while ((current = current->next))
	{
		if (current->value > max)
			max = current->value;
		else if (current->value < min)
			min = current->value;
	}
	current = inter->a;
	while (current)
	{
		current->value = (current->value - min) * 498 / (max - min + 1) + 2;
		current = current->next;
	}
}

void	img_erase(t_interface *inter)
{
	ft_bzero(inter->img_addr, inter->bits_per_pixel / 8
			* inter->size_x * inter->size_y);
}

void	img_pixel_put(t_interface *inter, int x, int y, int color)
{
	char			*pixel_addr;
	int				bytes_per_pixel;
	unsigned int	color_code;
	int				i;
	int				j;

	if (x >= 0 && x < inter->size_x && y >= 0 && y < inter->size_y)
	{
		bytes_per_pixel = inter->bits_per_pixel / 8;
		pixel_addr = inter->img_addr;
		pixel_addr += y * inter->size_line;
		pixel_addr += x * bytes_per_pixel;
		color_code = mlx_get_color_value(inter->mlx, color);
		i = 0;
		j = inter->endian ? bytes_per_pixel : 0;
		while (i < bytes_per_pixel)
		{
			ft_memcpy(pixel_addr + i, (char *)&color_code + j, 1);
			i++;
			inter->endian ? j-- : j++;
		}
	}
}

void	draw_line(t_interface *inter, int start_x, int start_y, t_stack *elem)
{
	int x;

	x = start_x;
	while (x <= start_x + elem->value)
	{
		img_pixel_put(inter, x, start_y,
						elem->status ? 0x0000FF00 : 0x00FFFFFF);
		x++;
	}
}

void	stacks_to_img(t_interface *inter)
{
	int x;
	int y;
	int i;

	x = 40;
	y = inter->size_y - 20;
	i = stack_length(inter->a);
	while (i > 0)
	{
		draw_line(inter, x, y, get_ith_stack(inter->a, i));
		y = y - 2;
		i--;
	}
	x = 580;
	y = inter->size_y - 20;
	i = stack_length(inter->b);
	while (i > 0)
	{
		draw_line(inter, x, y, get_ith_stack(inter->b, i));
		y = y - 2;
		i--;
	}
}
