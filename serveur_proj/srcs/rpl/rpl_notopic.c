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

void			rpl_notopic(t_user *this, t_channel *channel, t_server *server)
{
	t_query	*query;

	query = query_new(this);
	query->cmd = utils_concat(":%s 331 %s %s :No topic set",
			IRC_NAME, this->nick, channel->name);
	lst_push_back(server->querries, query);
}
