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

static bool		find_fn(void *data, void *ctx)
{
	return (ft_strcmp(((t_visual_channel *)data)->name, ctx) == 0);
}

void			visual_channel_del_by_name(t_visual *this, const char *chan)
{
	t_visual_channel	*channel;

	if (ft_strcmp(chan, "HOME") == 0)
		return ;
	channel = vector_find_pop(this->channels, find_fn, (void *)chan);
	if (channel == NULL)
		return ;
	if (channel == this->current)
	{
		this->current = vector_get_first(this->channels);
	}
	redrawwin(this->current->chat);
	wrefresh(this->current->chat);
	visual_channel_del(channel);
}
