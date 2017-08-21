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
	if (user_nick)
		free(user_nick);
	this->nick = ft_strdup(this->nick);
	if (this->nick && this->user)
	{
		user_try_connect(this, server);
	}
}
