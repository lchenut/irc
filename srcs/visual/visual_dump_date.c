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
#include <time.h>

void			visual_dump_date(t_visual *this)
{
	time_t		t;
	struct tm	*info;
	char		buffer[16];

	time(&t);
	info = localtime(&t);
	strftime(buffer, sizeof(buffer), "%H:%M:%S -- ", info);
	wattron(this->current->chat, COLOR_PAIR(VIS_COLOR_BOLD));
	waddstr(this->current->chat, buffer);
	wattroff(this->current->chat, COLOR_PAIR(VIS_COLOR_BOLD));
	wrefresh(this->current->chat);
}
