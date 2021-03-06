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

void			err_nonicknamegiven(t_user *this, t_server *server)
{
	t_query	*query;

	query = query_new(this);
	if (this->nick)
	{
		query->cmd = utils_concat(":%s 431 %s :No nickname given",
				IRC_NAME, this->nick);
	}
	else
	{
		query->cmd = utils_concat(":%s 431 :No nickname given", IRC_NAME);
	}
	lst_push_back(server->querries, query);
}
