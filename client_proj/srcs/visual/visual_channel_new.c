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

static bool				insert_fn(void *data, void *ctx)
{
	t_visual_channel	*current;
	t_visual_channel	*insert;

	current = data;
	insert = ctx;
	if (!ft_strcmp(current->name, " HOME "))
		return (false);
	return (ft_strcmp(current->name, insert->name) > 0);
}

void					visual_channel_new(t_visual *this, const char *name)
{
	t_visual_channel	*channel;

	if (visual_get_visual_channel(this, name))
	{
		return ;
	}
	channel = ft_calloc(sizeof(t_visual_channel));
	channel->name = ft_strdup(name);
	channel->chat = newwin(CHAT_NB_LINES, CHAT_NB_COLS,
			CHAT_START_LINES, CHAT_START_COLS);
	channel->users = vector_new();
	scrollok(channel->chat, true);
	vector_insert_when_match(this->channels, channel, insert_fn);
}
