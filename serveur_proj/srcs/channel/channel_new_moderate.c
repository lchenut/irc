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

#include "channel.h"
#include "user.h"
#include "server.h"

void			channel_new_moderate(t_channel *this, t_user *first,
		char *to_modo, t_server *server)
{
	t_user		*user;

	if (!to_modo)
		return ;
	if (!channel_is_user_joined(this, first))
	{
		err_notonchannel(first, this->name, server);
		return ;
	}
	if (vector_len(this->chanop) == 0 || channel_is_user_chanop(this, first))
	{
		user = server_get_user_from_nick(server, to_modo);
		if (user == NULL)
			err_nosuchnick(first, to_modo, server);
		else if (!channel_is_user_joined(this, user))
			err_notonchannel(first, to_modo, server);
		else if (!channel_is_user_moderate(this, user))
			vector_push_back(this->moderate, user);
	}
	else
	{
		err_chanoprivsneeded(first, this->name, server);
	}
}
