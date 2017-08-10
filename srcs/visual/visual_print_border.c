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
	wattron(this->border, COLOR_PAIR(VIS_COLOR_BORDER));
	wborder(this->border, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	mvwprintw(this->border, 0, 1, this->current->name);
	wattroff(this->border, COLOR_PAIR(VIS_COLOR_BORDER));
	wrefresh(this->border);
}
