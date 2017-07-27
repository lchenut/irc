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

#ifndef COMMAND_H
# define COMMAND_H

# include "basics.h"

typedef struct		s_line
{
	char			*line;
	char			*copy;
	size_t			total;
	size_t			size;
}					t_line;

t_line				*line_new(void);
void				line_del(t_line *this);

void				line_realloc(t_line *this);

typedef struct		s_command
{
	t_vector		*history;
	t_line			*last;
	unsigned char	buffer[8];
	size_t			curspos;
	size_t			winsize;
	size_t			index;
}					t_command;

t_command			*command_new(void);
void				command_del(t_command *this);

void				command_push(t_command *this, unsigned char c);

#endif
