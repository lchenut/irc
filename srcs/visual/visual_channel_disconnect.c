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

void			visual_channel_disconnect(t_visual *this)
{
	t_visual_channel	*channel;

	this->current = vector_get_first(this->channels);
	while (vector_len(this->channels) > 1)
	{
		channel = vector_pop_back(this->channels);
		visual_channel_del(channel);
	}
	redrawwin(this->current->chat);
	wrefresh(this->current->chat);
}
