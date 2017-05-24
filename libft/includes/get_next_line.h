/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:21:58 by atrudel           #+#    #+#             */
/*   Updated: 2016/11/23 17:15:04 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define BUFF_SIZE	 128

typedef struct		s_buffer
{
	int				fd;
	char			buff[BUFF_SIZE + 1];
	int				curseur;
	int				end;
}					t_buffer;

int					get_next_line(const int fd, char **line);

#endif
