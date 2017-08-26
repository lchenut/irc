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

static void		iter_fn(void *data, void *ctx1, void *ctx2)
{
	t_query		*query;

	query = query_new(data);
	query->cmd = ft_strdup(ctx1);
	lst_push_back(((t_server *)ctx2)->querries, query);
}

static char		*set_query_cmd(const char *cmd)
{
	char		*ret;
	size_t		i;

	if (!ft_strncmp(cmd, "ERROR: ", 7))
	{
		cmd += 7;
	}
	ret = ft_strnew(ft_strlen(cmd));
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\n' || (cmd[i] == '\r' && cmd[i + 1] == '\n'))
			break ;
		ret[i] = cmd[i];
		i += 1;
	}
	ret[i] = 0;
	return (ret);
}

void			user_exec_quit_from_query(t_user *this,
		t_query *query, t_server *server)
{
	char		*to_send;
	char		*cmd;

	if (!this->connected)
	{
		server_delete_user(server, this);
		return ;
	}
	if (query && query->cmd)
	{
		cmd = set_query_cmd(query->cmd);
		to_send = utils_concat(":%s!%s@%s QUIT :%s", this->nick, this->user,
				IRC_NAME, cmd);
		free(cmd);
	}
	else
	{
		to_send = utils_concat(":%s!%s@%s QUIT :Disconnected",
			this->nick, this->user, IRC_NAME);
	}
	vector_iter2(server->users, iter_fn, to_send, server);
	free(to_send);
	server_delete_user(server, this);
}
