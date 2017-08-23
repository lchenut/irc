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

void			channel_new_chanop(t_channel *this, t_user *first,
		char *to_chanop, t_server *server)
{
	t_user		*user;

	if (!to_chanop)
		return ;
	if (!channel_is_user_joined(this, first))
	{
		err_notonchannel(first, this->name, server);
		return ;
	}
	if (vector_len(this->chanop) == 0 || channel_is_user_chanop(this, first))
	{
		user = server_get_user_from_nick(server, to_chanop);
		if (user == NULL)
		{
			err_nosuchnick(first, to_chanop, server);
		}
		else if (!channel_is_user_joined(this, user))
		{
			err_notonchannel(first, to_chanop, server);
		}
		else if (!channel_is_user_chanop(this, user))
		{
			vector_push_back(this->chanop, user);
		}
	}
	else
	{
		err_chanoprivsneeded(first, this->name, server);
	}
}
