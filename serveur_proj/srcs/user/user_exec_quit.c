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

void			user_exec_quit(t_user *this, t_cmd *cmd, t_server *server)
{
	char		*to_send;

	if (!this->connected)
	{
		server_delete_user_from_socket(server, this->socket);
		return ;
	}
	if (cmd && vector_len(cmd->params) > 0)
	{
		to_send = utils_concat(":%s!%s@%s QUIT :%s", this->nick, this->user,
				IRC_NAME, vector_get_first(cmd->params));
	}
	else
	{
		to_send = utils_concat(":%s!%s@%s QUIT :Disconnected",
			this->nick, this->user, IRC_NAME);
	}
	vector_iter2(server->users, iter_fn, to_send, server);
	free(to_send);
	server_delete_user_from_socket(server, this->socket);
}
