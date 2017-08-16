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

t_exec_cmd		g_exec_cmd[] =
{
	{ "NICK", user_exec_nick },
	{ "USER", user_exec_user },
	{ "PASS", user_exec_pass },
	{ NULL, NULL }
};


void			user_exec_user(t_user *this, t_cmd *cmd, t_server *server)
{
	if (this->connected)
	{
		err_alreadyregistred(this, server);
		return ;
	}
	if (vector_len(cmd->params) < 4)
	{
		err_needmoreparams(this, cmd, server);
		return ;
	}
	this->user = ft_strdup(vector_get_first(cmd->params));
	if (this->nick && this->user)
	{
		user_try_connect(this, server);
	}
}

void			user_exec_pass(t_user *this, t_cmd *cmd, t_server *server)
{
	if (this->connected)
	{
		err_alreadyregistred(this, server);
		return ;
	}
	if (vector_len(cmd->params) == 0)
	{
		err_needmoreparams(this, cmd, server);
		return ;
	}
	if (this->pass)
		free(this->pass);
	this->pass = ft_strdup(vector_get_first(cmd->params));
	if (this->nick && this->user && this->pass)
	{
		user_try_connect(this, server);
	}
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
	if (g_exec_cmd[i].cmd)
	{
		g_exec_cmd[i].fn(this, cmd, server);
	}
	cmd_dump(cmd);
	cmd_del(cmd);
	(void)this;
	(void)server;
}
