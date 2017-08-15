/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 41:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H

# include "basics.h"

# define DFL_BUFFER_SIZE 512

typedef struct		s_buffer
{
	int				index;
	char			*buffer;
	size_t			total;
	size_t			start;
	size_t			end;
	size_t			size;
}					t_buffer;

t_buffer			*buffer_new(int fd);
void				buffer_del(t_buffer *this);

int					buffer_read_from_fd(t_buffer *this, int fd);
int					buffer_flush_fd(t_buffer *this, int fd);

char				*buffer_pop_line(t_buffer *this);

void				buffer_dump(t_buffer *this);

#endif
