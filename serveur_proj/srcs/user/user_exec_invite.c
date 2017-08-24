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

t_user			*get_invited(t_user *this, t_cmd *cmd, t_server *server)
{
	t_user		*invited;

	if (!this->connected)
		return (NULL);
	if (vector_len(cmd->params) < 2)
	{
		err_needmoreparams(this, cmd, server);
		return (NULL);
	}
	invited = server_get_user_from_nick(server, vector_get_first(cmd->params));
	if (invited == NULL || invited->connected == false)
	{
		err_nosuchnick(this, vector_get_first(cmd->params), server);
		return (NULL);
	}
	return (invited);
}

void			user_exec_invite(t_user *this, t_cmd *cmd, t_server *server)
{
	t_user		*invited;
	t_channel	*channel;

	if ((invited = get_invited(this, cmd, server)) == NULL)
		return ;
	channel = server_get_channel_from_name(server, vector_get(cmd->params, 1));
	if (!channel)
		return ;
	else if (!channel_is_user_joined(channel, this) &&
			!channel_is_user_chanop(channel, this))
		err_notonchannel(this, channel->name, server);
	else if (channel_is_user_joined(channel, invited))
		err_useronchannel(this, invited->nick, channel->name, server);
	else if (vector_len(channel->users) >= channel->limit)
		return ;
	else if (channel->mode.oninv && !channel_is_user_chanop(channel, this))
		err_chanoprivsneeded(this, channel->name, server);
	else
	{
		rpl_inviting(this, invited, channel, server);
		channel_new_user(channel, invited, server);
	}
}
