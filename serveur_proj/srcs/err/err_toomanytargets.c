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

void			err_toomanytargets(t_user *this, char *name, t_server *server)
{
	t_query	*query;

	query = query_new(this);
	query->cmd = utils_concat(":%s 407 %s %s :Password incorrect",
			IRC_NAME, this->nick, name);
	lst_push_back(server->querries, query);
}
