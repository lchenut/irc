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

void					visual_channel_new(t_visual *this, const char *name)
{
	t_visual_channel	*channel;

	channel = ft_calloc(sizeof(t_visual_channel));
	channel->name = ft_strdup(name);
	channel->chat = newwin(CHAT_NB_LINES, CHAT_NB_COLS,
			CHAT_START_LINES, CHAT_START_COLS);
	scrollok(channel->chat, true);
	vector_push_back(this->channels, channel);
}
