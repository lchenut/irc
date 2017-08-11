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

static void			visual_init_pair(void)
{
	init_color(COLOR_BLACK, 0, 0, 0);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	init_pair(VIS_COLOR_RED, 9, COLOR_BLACK);
	init_pair(VIS_COLOR_BOLD, 15, COLOR_BLACK);
	init_pair(VIS_COLOR_GREEN, 10, COLOR_BLACK);
	init_pair(VIS_COLOR_BORDER, COLOR_WHITE, COLOR_BLUE);
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
	this->current = vector_get_first(this->channels);
	this->prompt = newwin(PROMPT_NB_LINES, PROMPT_NB_COLS,
			PROMPT_START_LINES, PROMPT_START_COLS);
	this->border = newwin(BORDER_NB_LINES, BORDER_NB_COLS,
			BORDER_START_LINES, BORDER_START_COLS);
	visual_print_border(this);
	wrefresh(this->prompt);
	return (this);
}
