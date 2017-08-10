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

void			visual_print_bold(t_visual *this, char *s)
{
	wattron(this->current->chat, COLOR_PAIR(VIS_COLOR_BOLD));
	wprintw(this->current->chat, "%s\n", s);
	wattroff(this->current->chat, COLOR_PAIR(VIS_COLOR_BOLD));
	wrefresh(this->current->chat);
}
