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

#include "client.h"
#include "visual.h"
#include <signal.h>
#include <sys/ioctl.h>

static void			visual_init_pair(void)
{
	init_color(COLOR_BLACK, 0, 0, 0);
	init_color(COLOR_WHITE, 0x2a8, 0x2a8, 0x2a8);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	init_pair(VIS_COLOR_RED, 9, COLOR_BLACK);
	init_pair(VIS_COLOR_BOLD, 15, COLOR_BLACK);
	init_pair(VIS_COLOR_GREEN, 10, COLOR_BLACK);
	init_pair(VIS_COLOR_BORDER, COLOR_WHITE, COLOR_BLUE);
}

static void			iter_fn(void *data)
{
	wresize(((t_visual_channel *)data)->chat, CHAT_NB_LINES, CHAT_NB_COLS);
	mvwin(((t_visual_channel *)data)->chat, CHAT_START_LINES, CHAT_START_COLS);
}
/*
** TODO !!!!
*/
static void			sigwinch_handler(int sig)
{
	t_visual		*this;
	this = client_singleton()->visual;
	endwin();
	refresh();
	clear();
	wresize(this->border, BORDER_NB_LINES, BORDER_NB_COLS);
	mvwin(this->border, BORDER_START_LINES, BORDER_START_COLS);
	visual_print_border(this);
	return ;
	struct winsize	ws;

	ioctl(1, TIOCGWINSZ, &ws);
	clear();
	resize_term(ws.ws_row, ws.ws_col);
	this = client_singleton()->visual;
	wresize(this->prompt, PROMPT_NB_LINES, PROMPT_NB_COLS);
	mvwin(this->prompt, PROMPT_START_LINES, PROMPT_START_COLS);
	wresize(this->border, BORDER_NB_LINES, BORDER_NB_COLS);
	mvwin(this->border, BORDER_START_LINES, BORDER_START_COLS);
	vector_iter0(this->channels, iter_fn);
	visual_print_border(this);
	return ;
	//visual_print_prompt(this);
	doupdate();
	return ;
	visual_refresh_current(this);
	visual_move_curspos(this, command_get_curspos(client_singleton()->command));
	(void)sig;
}

t_visual			*visual_new(void)
{
	t_visual		*this;

	this = ft_calloc(sizeof(t_visual));
	initscr();
	noecho();
	start_color();
	visual_init_pair();
	this->channels = vector_new();
	visual_channel_new(this, "HOME");
	LOG_DEBUG("%zu", (size_t)BORDER_START_LINES);
	this->current = vector_get_first(this->channels);
	this->prompt = newwin(PROMPT_NB_LINES, PROMPT_NB_COLS,
			PROMPT_START_LINES, PROMPT_START_COLS);
	this->border = newwin(BORDER_NB_LINES, BORDER_NB_COLS,
			BORDER_START_LINES, BORDER_START_COLS);
	visual_print_border(this);
	wrefresh(this->prompt);
	this->index = 0;
	signal(SIGWINCH, sigwinch_handler);
	return (this);
}
