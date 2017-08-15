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

void			visual_print_bold(t_visual *this, char *s, char *chan)
{
	t_visual_channel	*channel;

	channel = visual_get_visual_channel(this, chan);
	if (channel == NULL)
	{
		return ;
	}
	wattron(channel->chat, COLOR_PAIR(VIS_COLOR_BOLD));
	wprintw(channel->chat, "%s", s);
	wattroff(channel->chat, COLOR_PAIR(VIS_COLOR_BOLD));
}
