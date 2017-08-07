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
#include "command.h"

static t_command_data	*cmd_new(char *low_cmd, char *upp_cmd)
{
	t_command_data		*data;

	data = ft_calloc(sizeof(t_command_data));
	data->low = low_cmd;
	data->upp = upp_cmd;
	return (data);
}

t_vector			*data_command(void)
{
	static t_vector	*data = NULL;

	if (!data)
	{
		data = vector_new();
		vector_push_back(data, cmd_new("/admin", "ADMIN"));
		vector_push_back(data, cmd_new("/away", "AWAY"));
		vector_push_back(data, cmd_new("/connect", "CONNECT"));
		vector_push_back(data, cmd_new("/error", "ERROR"));
		vector_push_back(data, cmd_new("/info", "INFO"));
		vector_push_back(data, cmd_new("/invite", "INVITE"));
		vector_push_back(data, cmd_new("/ison", "ISON"));
		vector_push_back(data, cmd_new("/join", "JOIN"));
		vector_push_back(data, cmd_new("/kick", "KICK"));
		vector_push_back(data, cmd_new("/kill", "KILL"));
		vector_push_back(data, cmd_new("/links", "LINKS"));
		vector_push_back(data, cmd_new("/list", "LIST"));
		vector_push_back(data, cmd_new("/mode", "MODE"));
		vector_push_back(data, cmd_new("/names", "NAMES"));
		vector_push_back(data, cmd_new("/nick", "NICK"));
		vector_push_back(data, cmd_new("/notice", "NOTICE"));
		vector_push_back(data, cmd_new("/oper", "OPER"));
		vector_push_back(data, cmd_new("/part", "PART"));
		vector_push_back(data, cmd_new("/pass", "PASS"));
		vector_push_back(data, cmd_new("/ping", "PING"));
		vector_push_back(data, cmd_new("/pong", "PONG"));
		vector_push_back(data, cmd_new("/privmsg", "PRIVMSG"));
		vector_push_back(data, cmd_new("/quit", "QUIT"));
		vector_push_back(data, cmd_new("/rehash", "REHASH"));
		vector_push_back(data, cmd_new("/restart", "RESTART"));
		vector_push_back(data, cmd_new("/server", "SERVER"));
		vector_push_back(data, cmd_new("/squit", "SQUIT"));
		vector_push_back(data, cmd_new("/stats", "STATS"));
		vector_push_back(data, cmd_new("/summon", "SUMMON"));
		vector_push_back(data, cmd_new("/time", "TIME"));
		vector_push_back(data, cmd_new("/topic", "TOPIC"));
		vector_push_back(data, cmd_new("/trace", "TRACE"));
		vector_push_back(data, cmd_new("/user", "USER"));
		vector_push_back(data, cmd_new("/userhost", "USERHOST"));
		vector_push_back(data, cmd_new("/users", "USERS"));
		vector_push_back(data, cmd_new("/version", "VERSION"));
		vector_push_back(data, cmd_new("/wallops", "WALLOPS"));
		vector_push_back(data, cmd_new("/who", "WHO"));
		vector_push_back(data, cmd_new("/whois", "WHOIS"));
		vector_push_back(data, cmd_new("/whowas", "WHOWAS"));
	}
	return (data);
}
