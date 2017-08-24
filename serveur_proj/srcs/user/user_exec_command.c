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
	{ "LIST", user_exec_list },
	{ "NAMES", user_exec_names },
	{ "PONG", user_exec_pong },
	{ "PART", user_exec_part },
	{ "QUIT", user_exec_quit },
	{ "MODE", user_exec_mode },
	{ "INVITE", user_exec_invite },
	{ NULL, NULL }
};

static void		flood_timeout(t_user *this, t_server *server)
{
	char		address[INET6_ADDRSTRLEN];
	t_query		*query;

	if (!inet_ntop(AF_INET6, &(this->sin.sin6_addr), address, sizeof(address)))
	{
		server_delete_user(server, this);
		return ;
	}
	ft_putstr("\033[34;1mflood timeout from ");
	ft_putstr(address);
	ft_putstr(" (port: ");
	ft_putnbr(this->sin.sin6_port);
	ft_putstr(")\033[0m\n");
	query = query_new(this);
	query->cmd = utils_concat("ERROR: Flood timeout");
	query->should_quit = true;
	lst_push_front(server->querries, query);
}

void			user_exec_command(t_user *this, char *line, t_server *server)
{
	t_cmd		*cmd;
	int			i;

	if (this->msg_nb >= 30)
	{
		flood_timeout(this, server);
		return ;
	}
	printf("Recv from %s: %s", this->nick, line);
	cmd = cmd_tokenizer_tokenize(line);
	if (!cmd->command)
	{
		cmd_del(cmd);
		return ;
	}
	i = 0;
	while (g_exec_cmd[i].cmd)
	{
		if (!ft_strcmp(g_exec_cmd[i].cmd, cmd->command))
			break ;
		i += 1;
	}
	if (g_exec_cmd[i].cmd)
		g_exec_cmd[i].fn(this, cmd, server);
	cmd_del(cmd);
}
