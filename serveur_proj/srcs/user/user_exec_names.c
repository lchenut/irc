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

/*
** TODO: Si le channel est prive ou secret
*/

static void		iter_fn(void *data, void *ctx1, void *ctx2)
{
	rpl_namreply(ctx1, data, ctx2);
	rpl_endofnames(ctx1, data, ctx2);
}

static void		exec_names_with_args(t_user *this, t_cmd *cmd, t_server *server)
{
	t_channel	*channel;
	char		**split;
	int			index;

	split = ft_strsplit(vector_get_first(cmd->params), ',');
	index = 0;
	while (split[index])
	{
		channel = server_get_channel_from_name(server, split[index]);
		if (channel != NULL)
		{
			rpl_namreply(this, channel, server);
			rpl_endofnames(this, channel, server);
		}
		index += 1;
	}
	array_del(split);
}

void			user_exec_names(t_user *this, t_cmd *cmd, t_server *server)
{
	if (!this->connected)
		return ;
	if (vector_len(cmd->params) == 0)
	{
		vector_iter2(server->channels, iter_fn, this, server);
	}
	else
	{
		exec_names_with_args(this, cmd, server);
	}
}
