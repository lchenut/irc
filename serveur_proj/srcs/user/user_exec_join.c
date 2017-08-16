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
#include "array.h"

void			user_exec_join(t_user *this, t_cmd *cmd, t_server *server)
{
	char		**channels;
	char		**keys;
	size_t		keylen;
	size_t		index;
	t_channel	*chan;

	if (!this->connected)
		return ;
	if (vector_len(cmd->params) == 0)
	{
		err_needmoreparams(this, cmd, server);
		return ;
	}
	channels = ft_strsplit(vector_get_first(cmd->params), ',');
	if (vector_len(cmd->params) > 1)
	{
		keys = ft_strsplit(vector_get(cmd->params, 1), ',');
		keylen = array_len(keys);
	}
	else
	{
		keys = NULL;
		keylen = 0;
	}
	index = 0;
	while (channels[index])
	{
		if (!utils_is_valid_channame(channels[index]))
			err_nosuchchannel(this, channels[index], server);
		else if (!(chan = server_create_or_get_channel(server, channels[index],
				index < keylen && *keys[index] ? keys[index] : NULL)))
			err_nosuchchannel(this, channels[index], server);
		else if (chan->mode.oninv)
			err_inviteonlychan(this, channels[index], server);
		else if (vector_len(chan->users) >= chan->limit)
			err_channelisfull(this, channels[index], server);
		else if ((index < keylen && *keys[index] &&
					ft_strcmp(chan->key, keys[index])) || chan->key != NULL)
			err_badchannelkey(this, channels[index], server);
		else
			channel_new_user(chan, this, server);
		index += 1;
	}
}
