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
#include "array.h"

void			user_exec_part(t_user *this, t_cmd *cmd, t_server *server)
{
	char		**channels;
	size_t		index;
	t_channel	*channel;

	if (!this->connected)
		return ;
	if (vector_len(cmd->params) == 0)
	{
		err_needmoreparams(this, cmd, server);
		return ;
	}
	channels = ft_strsplit_empty(vector_get_first(cmd->params), ',');
	index = 0;
	while (channels[index])
	{
		channel = server_get_channel_from_name(server, channels[index]);
		if (!channel)
			err_nosuchchannel(this, channels[index], server);
		else if (!channel_is_user_joined(channel, this))
			err_notonchannel(this, channels[index], server);
		else
			channel_user_part(channel, this, server);
		index += 1;
	}
	array_del(channels);
}
