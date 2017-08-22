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

#include "user.h"
#include "server.h"

/*
** TODO: Gerer le topic lock (mode)
*/

static t_channel	*exec_topic_get_channel(t_user *this, t_cmd *cmd,
		t_server *server)
{
	t_channel		*channel;

	if (!this->connected)
		return (NULL);
	if (vector_len(cmd->params) == 0)
	{
		err_needmoreparams(this, cmd, server);
		return (NULL);
	}
	channel = server_get_channel_from_name(server,
			vector_get_first(cmd->params));
	if (channel == NULL)
	{
		err_nosuchchannel(this, vector_get_first(cmd->params), server);
	}
	return (channel);
}

void				user_exec_topic(t_user *this, t_cmd *cmd, t_server *server)
{
	t_channel		*channel;
	char			*topic;

	if ((channel = exec_topic_get_channel(this, cmd, server)) == NULL)
		return ;
	if (!channel_is_user_joined(channel, this))
	{
		err_notonchannel(this, channel->name, server);
		return ;
	}
	if (vector_len(cmd->params) > 1)
	{
		topic = vector_get(cmd->params, 1);
		if (channel->topic)
			free(channel->topic);
		channel->topic = ft_strdup(topic);
	}
	else if (channel->topic)
		rpl_topic(this, channel, server);
	else
		rpl_notopic(this, channel, server);
}
