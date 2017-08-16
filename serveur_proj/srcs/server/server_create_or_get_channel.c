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

#include "server.h"

t_channel		*server_create_or_get_channel(t_server *this,
		char *name, char *key)
{
	t_channel	*channel;

	channel = server_get_channel_from_name(this, name);
	if (channel)
	{
		return (channel);
	}
	if (vector_len(this->channels) > this->maxchannels)
	{
		return (NULL);
	}
	channel = channel_new(name, key);
	if (!channel)
	{
		return (NULL);
	}
	vector_push_back(this->channels, channel);
	return (channel);
}
