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

static bool		exists_fn(void *data, void *context)
{
	t_user		*user_data;
	t_user		*user_context;

	if (data == context)
		return (false);
	user_data = data;
	user_context = context;
	if (user_data->nick == NULL)
		return (false);
	return (ft_strcmp(user_data->nick, user_context->nick) == 0);
}

static bool		user_exec_nick_error(t_user *this, t_cmd *cmd,
		t_server *server, char *user_nick)
{
	if (!user_nick && vector_exists(server->users, exists_fn, this))
	{
		this->nick = user_nick;
		err_nickcollision(this, vector_get_first(cmd->params), server);
		return (true);
	}
	else if (vector_exists(server->users, exists_fn, this))
	{
		this->nick = user_nick;
		err_nicknameinuse(this, vector_get_first(cmd->params), server);
		return (true);
	}
	else if (!utils_is_valid_nickname(this->nick))
	{
		this->nick = user_nick;
		err_erroneusnickname(this, vector_get_first(cmd->params), server);
		return (true);
	}
	return (false);
}

static void		iter_fn(void *data, void *ctx1, void *ctx2)
{
	t_query		*query;

	query = query_new(data);
	query->cmd = ft_strdup(ctx1);
	lst_push_back(((t_server *)ctx2)->querries, query);
}

static void		user_change_nick(t_user *this, t_server *server, char *old)
{
	char		*to_send;

	if (!ft_strcmp(this->nick, old))
		return ;
	to_send = utils_concat(":%s!%s@%s NICK %s", old, this->user,
			IRC_NAME, this->nick);
	vector_iter2(server->users, iter_fn, to_send, server);
}

void			user_exec_nick(t_user *this, t_cmd *cmd, t_server *server)
{
	char		*user_nick;

	if (vector_len(cmd->params) == 0)
	{
		err_nonicknamegiven(this, server);
		return ;
	}
	user_nick = this->nick;
	this->nick = vector_get_first(cmd->params);
	if (user_exec_nick_error(this, cmd, server, user_nick))
		return ;
	this->nick = ft_strdup(this->nick);
	if (this->nick && this->user && !this->connected)
	{
		user_try_connect(this, server);
	}
	else if (this->connected)
	{
		user_change_nick(this, server, user_nick);
	}
	if (user_nick)
		free(user_nick);
}
