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
	char		buf[512];
	char		*tmp;
	t_querry	*querry;

	querry = querry_new(this);
	buf[0] = 0;
	tmp = utils_concat(buf, ":");
	tmp = utils_concat(tmp, IRC_NAME);
	tmp = utils_concat(tmp, " 002 ");
	tmp = utils_concat(tmp, this->nick);
	tmp = utils_concat(tmp, " :Your host is ");
	tmp = utils_concat(tmp, IRC_NAME);
	tmp = utils_concat(tmp, ", running version 1.0.0\r\n");
	querry->cmd = ft_strdup(buf);
	lst_push_back(server->querries, querry);
}
