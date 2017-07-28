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

t_visual			*visual_new(void)
{
	t_visual		*this;

	this = ft_calloc(sizeof(t_visual));
	initscr();
	noecho();
	this->chat = newwin(CHAT_NB_LINES, CHAT_NB_COLS,
			CHAT_START_LINES, CHAT_START_COLS);
	scrollok(this->chat, true);
	this->prompt = newwin(PROMPT_NB_LINES, PROMPT_NB_COLS,
			PROMPT_START_LINES, PROMPT_START_COLS);
	this->border = newwin(BORDER_NB_LINES, BORDER_NB_COLS,
			BORDER_START_LINES, BORDER_START_COLS);
	box(this->border, 0, 0);
	wrefresh(this->border);
	wrefresh(this->prompt);
	return (this);
}
