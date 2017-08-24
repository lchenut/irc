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
#include "cmd.h"
#include "channel.h"

void			user_exec_chanmode(t_user *this, t_cmd *cmd,
		t_server *server, t_channel *channel)
{
	char		*mode;

	mode = vector_get(cmd->params, 1);
	if (mode == NULL || (mode[0] != '+' && mode[0] != '-'))
	{
		rpl_channelmodeis(this, channel, mode, server);
	}
	else if (vector_len(channel->chanop) != 0 &&
			!channel_is_user_chanop(channel, this))
	{
		if (!channel_is_user_joined(channel, this))
			err_notonchannel(this, channel->name, server);
		else
			err_chanoprivsneeded(this, channel->name, server);
	}
	else if (mode[0] == '+')
	{
		user_exec_chanmode_plus(this, cmd, server, channel);
	}
	else
	{
		user_exec_chanmode_minus(this, cmd, server, channel);
	}
}
