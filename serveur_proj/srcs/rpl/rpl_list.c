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

#include "rpl.h"
#include "server.h"
#include "user.h"
#include "channel.h"
#include "xstdlib.h"

void			rpl_list(t_user *this, t_channel *channel, t_server *server)
{
	t_query		*query;
	char		*nb;

	query = query_new(this);
	nb = ft_itoa(vector_len(channel->users));
	if (channel->mode.secret)
	{
		if (channel_is_user_joined(channel, this))
			query->cmd = utils_concat(":%s 322 %s %s Sec %s :%s", IRC_NAME,
					this->nick, channel->name, nb,
					channel->topic ? channel->topic : "");
	}
	else if (channel->mode.private)
		query->cmd = utils_concat(":%s 322 %s %s Prv %s :%s", IRC_NAME,
				this->nick, channel->name, nb,
				(channel_is_user_joined(channel, this) && channel->topic) ?
				channel->topic : "");
	else
		query->cmd = utils_concat(":%s 322 %s %s Nor %s :%s", IRC_NAME,
				this->nick, channel->name, nb,
				channel->topic ? channel->topic : "");
	free(nb);
	if (query->cmd == NULL)
		query_del(query);
	else
		lst_push_back(server->querries, query);
}
