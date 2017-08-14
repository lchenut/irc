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

#include "replies.h"
#include "client.h"

static void			iter_fn(void *data, int index)
{
	LOG_INFO("param[%i]: %s", index, data);
}

void				reply_dump(t_rpl_cnt *this)
{
	LOG_INFO("======================");
	LOG_INFO("Current user: %s", client_singleton()->nick);
	if (this->servername)
	{
		LOG_INFO("servername: %s", this->servername);
	}
	else
	{
		LOG_INFO("nick: %s", this->nick);
		LOG_INFO("user: %s", this->user);
		LOG_INFO("host: %s", this->host);
	}
	LOG_INFO("command: %s", this->command);
	vector_iteri0(this->params, iter_fn);
	LOG_INFO("======================");
}
