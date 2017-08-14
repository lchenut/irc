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

# define PROMPT_SIZE 12

# define CHAT_NB_LINES (LINES - 2)
# define CHAT_NB_COLS (COLS)
# define CHAT_START_LINES 0
# define CHAT_START_COLS 0

# define PROMPT_NB_LINES 1
# define PROMPT_NB_COLS (COLS - 2)
# define PROMPT_START_LINES (LINES - 1)
# define PROMPT_START_COLS 1

# define BORDER_NB_LINES 1
# define BORDER_NB_COLS COLS
# define BORDER_START_LINES (LINES - 2)
# define BORDER_START_COLS 0

# define VIS_COLOR_RED 40
# define VIS_COLOR_BOLD 41
# define VIS_COLOR_GREEN 42
# define VIS_COLOR_BORDER 43

typedef struct			s_visual_channel
{
	char				*name;
	WINDOW				*chat;
	t_vector			*users;
	size_t				longest_users_name;
	size_t				current_line;
}						t_visual_channel;

typedef struct			s_visual
{
	WINDOW				*prompt;
	WINDOW				*border;
	t_visual_channel	*current;
	t_vector			*channels;
	size_t				index;
}						t_visual;

t_visual				*visual_new(void);
void					visual_del(t_visual *this);

void					visual_channel_new(t_visual *this, const char *s);
void					visual_channel_del(t_visual_channel *this);
void					visual_channel_del_by_name(t_visual *this,
		const char *chan);
void					visual_channel_disconnect(t_visual *this);
t_visual_channel		*visual_get_visual_channel(t_visual *this,
		const char *chan);

void					visual_refresh_current(t_visual *this);


void					visual_print_border(t_visual *this);
void					visual_print_prompt(t_visual *this, char *buf);
void					visual_dump_date(t_visual *this, char *chan);
void					visual_print_newline(t_visual *this, char *chan);

// =============================================================================
void					visual_print_channel(t_visual *this, char *buf, char *chan);
void					visual_perror(t_visual *this, char *buf, char *chan);
void					visual_print_bold(t_visual *this, char *buf, char *chan);
void					visual_print_green(t_visual *this, char *buf, char *chan);
void					visual_print_red(t_visual *this, char *buf, char *chan);

void					visual_move_curspos(t_visual *this, int x);
char					visual_get_char(t_visual *this);

void					visual_dump_channel(t_visual *this,
		char *chan, char *msg);

void					visual_chat_incr(t_visual *this);
void					visual_chat_decr(t_visual *this);

void					visual_clear_prompt(t_visual *this);


#endif
