/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:27:48 by smanta            #+#    #+#             */
/*   Updated: 2019/10/21 17:44:29 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# define BUFF_SIZE 10

typedef struct	s_fd
{
	int			fd;
	int			ind;
	char		buf[BUFF_SIZE + 1];
	struct s_fd	*next;
	struct s_fd	*prev;
}				t_fd;

int				get_next_line(const int fd, char **line);

#endif
