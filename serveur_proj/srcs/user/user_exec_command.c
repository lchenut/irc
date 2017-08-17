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
	{ "PRIVMSG", user_exec_privmsg },
	{ NULL, NULL }
};

static t_vector	*get_dest(t_user *this, t_cmd *cmd, t_server *server)
{
	char		**array;
	t_vector	*dest;
	int			index;
	int			tmp;

	array = ft_strsplit(vector_get_first(cmd->params), ',');
	dest = vector_new();
	index = 0;
	while (array[index])
	{
		if (array[index][0] != '\0')
		{
			tmp = index - 1;
			while (tmp >= 0 && !ft_strcmp(array[index], array[tmp]))
				tmp -= 1;
			if (tmp != -1)
				err_toomanytargets(this, array[index], server);
			else
				vector_push_back(dest, ft_strdup(array[index]));
		}
		index += 1;
	}
	array_del(array);
	return (dest);
}

static void		exec_privmsg_to_user(t_user *this, t_cmd *cmd,
		t_server *server, t_user *dest)
{
	char		buf[512];
	char		*tmp;
	t_querry	*querry;

	querry = querry_new(this);
	buf[0] = 0;
	tmp = utils_concat(buf, ":");
	tmp = utils_concat(tmp, this->nick);
	tmp = utils_concat(tmp, "!");
	tmp = utils_concat(tmp, this->user);
	tmp = utils_concat(tmp, "@");
	tmp = utils_concat(tmp, IRC_NAME);
	tmp = utils_concat(tmp, " PRIVMSG ");
	tmp = utils_concat(tmp, dest->nick);
	tmp = utils_concat(tmp, " :");
	tmp = utils_concat(tmp, vector_get(cmd->params, 1));
	tmp = utils_concat(tmp, "\r\n");
	querry->cmd = ft_strdup(buf);
	lst_push_back(server->querries, querry);
}

static void		exec_privmsg_to_channel(t_user *this, t_cmd *cmd,
		t_server *server, t_channel *dest)
{
	char		buf[512];
	char		*tmp;

	if (channel_is_user_joined(dest, this) && dest->mode.msgrestricted)
	{
		err_cannotsendtochan(this, dest->name, server);
		return ;
	}
	buf[0] = 0;
	tmp = utils_concat(buf, ":");
	tmp = utils_concat(tmp, this->nick);
	tmp = utils_concat(tmp, "!");
	tmp = utils_concat(tmp, this->user);
	tmp = utils_concat(tmp, "@");
	tmp = utils_concat(tmp, IRC_NAME);
	tmp = utils_concat(tmp, " PRIVMSG ");
	tmp = utils_concat(tmp, dest->name);
	tmp = utils_concat(tmp, " :");
	tmp = utils_concat(tmp, vector_get(cmd->params, 1));
	tmp = utils_concat(tmp, "\r\n");
	tmp = ft_strdup(buf);
	channel_send_msg_from(dest, this, tmp, server);
	free(tmp);
}

static void		exec_privmsg(t_user *this, t_cmd *cmd, t_server *server)
{
	t_vector	*dest;
	t_channel	*channel;
	t_user		*user;
	char		*d;

	dest = get_dest(this, cmd, server);
	if (vector_len(dest) == 0)
		err_norecipient(this, cmd->command, server);
	else
	{
		while ((d = vector_pop_back(dest)))
		{
			if ((channel = server_get_channel_from_name(server, d)))
				exec_privmsg_to_channel(this, cmd, server, channel);
			else if ((user = server_get_user_from_nick(server, d)))
				exec_privmsg_to_user(this, cmd, server, user);
			else
				err_nosuchchannel(this, d, server);
			free(d);
		}
	}
	vector_del(dest, free);
}

void			user_exec_privmsg(t_user *this, t_cmd *cmd, t_server *server)
{
	if (vector_len(cmd->params) == 0)
		err_norecipient(this, cmd->command, server);
	else if (vector_len(cmd->params) == 1)
		err_notextsend(this, server);
	else
		exec_privmsg(this, cmd, server);
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
		printf("Alo\n");
		g_exec_cmd[i].fn(this, cmd, server);
		printf("Alo\n");
	}
	cmd_del(cmd);
	(void)this;
	(void)server;
}
