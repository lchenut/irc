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
# include "line.h"

typedef struct		s_command
{
	t_vector		*history;
	t_line			*current;
	t_line			*last;
	char			buffer[8];
	size_t			curspos;
	size_t			winsize;
	size_t			index;
}					t_command;

t_command			*command_new(void);
void				command_del(t_command *this);

void				command_push(t_command *this, char c);
char				*command_get_line(t_command *this);
char				*command_get_line_scaled(t_command *this);
size_t				command_get_curspos(t_command *this);

void				command_move_left(t_command *this);
void				command_move_right(t_command *this);
void				command_del_left(t_command *this);
void				command_del_right(t_command *this);
void				command_move_home(t_command *this);
void				command_move_end(t_command *this);
void				command_history_up(t_command *this);
void				command_history_down(t_command *this);

void				command_history_push(t_command *this);

#endif
