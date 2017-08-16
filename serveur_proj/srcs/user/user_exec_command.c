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
#include "channel.h"

t_exec_cmd		g_exec_cmd[] =
{
	{ "NICK", user_exec_nick },
	{ "USER", user_exec_user },
	{ "PASS", user_exec_pass },
	{ "JOIN", user_exec_join },
	{ "TOPIC", user_exec_topic },
	{ "PRIVMSG", NULL },
	{ NULL, NULL }
};

void			user_exec_topic(t_user *this, t_cmd *cmd, t_server *server)
{
	t_channel	*channel;
	char		*topic;

	if (!this->connected)
		return ;
	if (vector_len(cmd->params) == 0)
	{
		err_needmoreparams(this, cmd, server);
		return ;
	}
	channel = server_get_channel_from_name(server, vector_get_first(cmd->params));
	if (channel == NULL)
		return ;
	if (!channel_is_user_joined(channel, this))
	{
		err_notonchannel(this, channel->name, server);
		return ;
	}
	if (vector_len(cmd->params) > 1)
	{
		// topiclock
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

void			user_exec_command(t_user *this, char *line, t_server *server)
{
	t_cmd		*cmd;
	int			i;
	
	cmd = cmd_tokenizer_tokenize(line);
	i = 0;
	while (g_exec_cmd[i].cmd)
	{
		if (!ft_strcmp(g_exec_cmd[i].cmd, cmd->command))
		{
			break ;
		}
		i += 1;
	}
	cmd_dump(cmd);
	if (g_exec_cmd[i].cmd)
	{
		g_exec_cmd[i].fn(this, cmd, server);
	}
	cmd_del(cmd);
	(void)this;
	(void)server;
}
