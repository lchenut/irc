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

void			err_unknownmode(t_user *this, char mode, t_server *server)
{
	char		buf[2];
	t_query		*query;

	query = query_new(this);
	buf[0] = mode;
	buf[1] = 0;
	query->cmd = utils_concat(":%s 472 %s :is unknown mode char to me",
			IRC_NAME, buf);
	lst_push_back(server->querries, query);
}
