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

# define DFL_BUFFER_SIZE 256

typedef struct		s_buffer
{
	int				fd;
	char			*buffer;
	size_t			total;
	size_t			current;
}					t_buffer;

t_buffer			*buffer_new(int fd);
void				buffer_del(t_buffer *this);

void				buffer_strcat(t_buffer *this, char *s);
char				*buffer_get_line(t_buffer *this);

void				buffer_realloc(t_buffer *this);

#endif
