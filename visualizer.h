/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 10:56:09 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/03 19:40:24 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include <mlx.h>
# include "push_swap.h"

typedef struct	s_interface
{
	void		*mlx;
	void		*win;
	void		*img;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			size_x;
	int			size_y;
	char		*img_addr;
	int			fd;
	t_stack		*a;
	t_stack		*b;
	int			delay;
	int			instruction_count;
	int			color;
}				t_interface;

void			stacks_to_img(t_interface *inter);
void			img_erase(t_interface *inter);
void			scale(t_interface *inter);

#endif
