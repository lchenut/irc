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

#include "visual.h"

void				visual_print_border(t_visual *this)
{
	wattron(this->border, COLOR_PAIR(43));
	box(this->border, 0, 0);
	wattroff(this->border, COLOR_PAIR(43));
	wattron(this->border, COLOR_PAIR(44));
	mvwprintw(this->border, 0, 1, "TEST");
	wattroff(this->border, COLOR_PAIR(44));
	wrefresh(this->border);
}

t_visual			*visual_new(void)
{
	t_visual		*this;

	this = ft_calloc(sizeof(t_visual));
	initscr();
	noecho();
	start_color();
	init_pair(40, 9, COLOR_BLACK);
	init_pair(41, 15, COLOR_BLACK);
	init_pair(42, 10, COLOR_BLACK);
	init_pair(43, COLOR_BLUE, COLOR_BLUE);
	init_pair(44, COLOR_WHITE, COLOR_BLUE);
	this->chat = newwin(CHAT_NB_LINES, CHAT_NB_COLS,
			CHAT_START_LINES, CHAT_START_COLS);
	scrollok(this->chat, true);
	this->prompt = newwin(PROMPT_NB_LINES, PROMPT_NB_COLS,
			PROMPT_START_LINES, PROMPT_START_COLS);
	this->border = newwin(BORDER_NB_LINES, BORDER_NB_COLS,
			BORDER_START_LINES, BORDER_START_COLS);
	wrefresh(this->prompt);
	visual_print_border(this);
	return (this);
}
