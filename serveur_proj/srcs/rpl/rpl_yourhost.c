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

void			rpl_yourhost(t_user *this, t_server *server)
{
	t_query	*query;

	query = query_new(this);
	query->cmd = utils_concat(
			":%s 002 %s :Your host is %s, running version 1.0.0",
			IRC_NAME, this->nick, IRC_NAME);
	lst_push_back(server->querries, query);
}
