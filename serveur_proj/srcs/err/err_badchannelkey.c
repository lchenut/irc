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

void			err_badchannelkey(t_user *this, char *name, t_server *server)
{
	t_query	*query;

	query = query_new(this);
	query->cmd = utils_concat(":%s 475 %s :Cannot join channel (+k)",
			IRC_NAME, name);
	lst_push_back(server->querries, query);
}
