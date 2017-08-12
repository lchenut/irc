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

void			visual_print_newline(t_visual *this, char *chan)
{
	t_visual_channel	*channel;

	channel = visual_get_visual_channel(this, chan);
	if (channel == NULL)
	{
		return ;
	}
	waddch(channel->chat, '\n');
	if (channel == this->current)
	{
		wrefresh(channel->chat);
	}
}
