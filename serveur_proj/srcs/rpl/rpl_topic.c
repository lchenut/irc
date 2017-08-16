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

void			rpl_topic(t_user *this, t_channel *channel, t_server *server)
{
	char		buf[512];
	char		*tmp;
	t_querry	*querry;

	querry = querry_new(this);
	buf[0] = 0;
	tmp = utils_concat(buf, ":");
	tmp = utils_concat(tmp, IRC_NAME);
	tmp = utils_concat(tmp, " 332 ");
	tmp = utils_concat(tmp, this->nick);
	tmp = utils_concat(tmp, " ");
	tmp = utils_concat(tmp, channel->name);
	tmp = utils_concat(tmp, " :");
	tmp = utils_concat(tmp, channel->topic);
	tmp = utils_concat(tmp, "\r\n");
	querry->cmd = ft_strdup(buf);
	lst_push_back(server->querries, querry);
}
