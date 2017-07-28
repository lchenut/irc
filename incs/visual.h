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

#ifndef VISUAL_H
# define VISUAL_H

# include "basics.h"
# include <ncurses.h>

# define CHAT_NB_LINES (LINES - 4)
# define CHAT_NB_COLS (COLS - 2)
# define CHAT_START_LINES 1
# define CHAT_START_COLS 1

# define PROMPT_NB_LINES 1
# define PROMPT_NB_COLS (COLS - 4)
# define PROMPT_START_LINES (LINES - 2)
# define PROMPT_START_COLS 2

# define BORDER_NB_LINES 3
# define BORDER_NB_COLS COLS
# define BORDER_START_LINES (LINES - 3)
# define BORDER_START_COLS 0

typedef struct		s_visual
{
	WINDOW			*chat;
	WINDOW			*prompt;
	WINDOW			*border;
}					t_visual;

t_visual			*visual_new(void);
void				visual_del(t_visual *this);

void				visual_print_chat(t_visual *this, char *buf);
void				visual_print_prompt(t_visual *this, char *buf);
void				visual_move_curspos(t_visual *this, int x);
char				visual_get_char(t_visual *this);

void				visual_clear_prompt(t_visual *this);

#endif
