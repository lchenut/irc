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

#include "data.h"
#include "client.h"

static t_command_data	*cmd_new(char *low_cmd, char *upp_cmd,
		void (*fn)(t_client *, char *cmd))
{
	t_command_data		*data;

	data = ft_calloc(sizeof(t_command_data));
	data->low = low_cmd;
	data->upp = upp_cmd;
	data->exec_fn = fn;
	return (data);
}

static void				data_command_push01(t_vector *data)
{
	vector_push_back(data, cmd_new("/admin", "ADMIN", NULL));
	vector_push_back(data, cmd_new("/away", "AWAY", NULL));
	vector_push_back(data, cmd_new("/connect", "CONNECT", client_exec_connect));
	vector_push_back(data, cmd_new("/error", "ERROR", NULL));
	vector_push_back(data, cmd_new("/info", "INFO", NULL));
	vector_push_back(data, cmd_new("/invite", "INVITE", NULL));
	vector_push_back(data, cmd_new("/ison", "ISON", NULL));
	vector_push_back(data, cmd_new("/join", "JOIN", client_exec_join));
	vector_push_back(data, cmd_new("/kick", "KICK", NULL));
	vector_push_back(data, cmd_new("/kill", "KILL", NULL));
	vector_push_back(data, cmd_new("/links", "LINKS", NULL));
	vector_push_back(data, cmd_new("/list", "LIST", client_exec_list));
	vector_push_back(data, cmd_new("/mode", "MODE", NULL));
	vector_push_back(data, cmd_new("/names", "NAMES", client_exec_names));
	vector_push_back(data, cmd_new("/nick", "NICK", NULL));
	vector_push_back(data, cmd_new("/notice", "NOTICE", NULL));
	vector_push_back(data, cmd_new("/oper", "OPER", NULL));
	vector_push_back(data, cmd_new("/part", "PART", client_exec_part));
	vector_push_back(data, cmd_new("/pass", "PASS", NULL));
	vector_push_back(data, cmd_new("/ping", "PING", NULL));
}

static void				data_command_push02(t_vector *data)
{
	vector_push_back(data, cmd_new("/pong", "PONG", NULL));
	vector_push_back(data, cmd_new("/privmsg", "PRIVMSG", client_exec_privmsg));
	vector_push_back(data, cmd_new("/quit", "QUIT", client_exec_quit));
	vector_push_back(data, cmd_new("/rehash", "REHASH", NULL));
	vector_push_back(data, cmd_new("/restart", "RESTART", NULL));
	vector_push_back(data, cmd_new("/server", "SERVER", NULL));
	vector_push_back(data, cmd_new("/squit", "SQUIT", NULL));
	vector_push_back(data, cmd_new("/stats", "STATS", NULL));
	vector_push_back(data, cmd_new("/summon", "SUMMON", NULL));
	vector_push_back(data, cmd_new("/time", "TIME", NULL));
	vector_push_back(data, cmd_new("/topic", "TOPIC", client_exec_topic));
	vector_push_back(data, cmd_new("/trace", "TRACE", NULL));
	vector_push_back(data, cmd_new("/user", "USER", NULL));
	vector_push_back(data, cmd_new("/userhost", "USERHOST", NULL));
	vector_push_back(data, cmd_new("/users", "USERS", NULL));
	vector_push_back(data, cmd_new("/version", "VERSION", NULL));
	vector_push_back(data, cmd_new("/wallops", "WALLOPS", NULL));
	vector_push_back(data, cmd_new("/who", "WHO", NULL));
	vector_push_back(data, cmd_new("/whois", "WHOIS", NULL));
	vector_push_back(data, cmd_new("/whowas", "WHOWAS", NULL));
}

t_vector				*data_command(void)
{
	static t_vector	*data = NULL;

	if (!data)
	{
		data = vector_new();
		data_command_push01(data);
		data_command_push02(data);
	}
	return (data);
}
