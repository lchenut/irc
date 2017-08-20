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

/*
** TODO: SI PRIVE OU SECRET...
*/

void			rpl_list(t_user *this, t_channel *channel, t_server *server)
{
	t_query		*query;
	char		*nb;

	query = query_new(this);
	nb = ft_itoa(vector_len(channel->users));
	query->cmd = utils_concat(":%s 322 %s %s %s %s :%s", IRC_NAME, this->nick,
			channel->name, "<TODO VISIBILITY>", nb,
			channel->topic ? channel->topic : "");
	free(nb);
	lst_push_back(server->querries, query);
}
