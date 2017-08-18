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
#include "array.h"

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
	t_query	*query;

	query = query_new(dest);
	query->cmd = utils_concat(":%s!%s@%s PRIVMSG %s :%s",
	this->nick, this->user, IRC_NAME, dest->nick, vector_get(cmd->params, 1));
	lst_push_back(server->querries, query);
}

static void		exec_privmsg_to_channel(t_user *this, t_cmd *cmd,
		t_server *server, t_channel *dest)
{
	char		*tosend;

	if (channel_is_user_joined(dest, this) && dest->mode.msgrestricted)
	{
		err_cannotsendtochan(this, dest->name, server);
		return ;
	}
	tosend = utils_concat(":%s!%s@%s PRIVMSG %s :%s",
	this->nick, this->user, IRC_NAME, dest->name, vector_get(cmd->params, 1));
	channel_send_msg_from(dest, this, tosend, server);
	free(tosend);
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
				err_nosuchnick(this, d, server);
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
