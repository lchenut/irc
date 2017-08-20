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

static void		init_keys(t_cmd *cmd, char ***keys)
{
	char		**keys_tmp;
	int			index;

	keys_tmp = ft_strsplit_empty(vector_get(cmd->params, 1), ',');
	index = 0;
	while (keys_tmp[index])
	{
		if (keys_tmp[index][0])
			(*keys)[index] = ft_strdup(keys_tmp[index]);
		index += 1;
	}
	array_del(keys_tmp);
}

static char		**init_channels_keys(t_user *this, t_cmd *cmd,
		t_server *server, char ***keys)
{
	char		**channels;

	if (!this->connected)
		return (NULL);
	if (vector_len(cmd->params) == 0)
	{
		err_needmoreparams(this, cmd, server);
		return (NULL);
	}
	channels = ft_strsplit(vector_get_first(cmd->params), ',');
	(*keys) = ft_calloc(sizeof(char *) * (array_len(channels) + 1));
	if (vector_len(cmd->params) > 1)
	{
		init_keys(cmd, keys);
	}
	return (channels);
}

static void		delete_channels_keys(char **channels, char **keys)
{
	size_t		index;

	index = 0;
	while (channels[index])
	{
		if (keys[index])
			free(keys[index]);
		free(channels[index]);
		index += 1;
	}
	free(keys);
	free(channels);
}

void			user_exec_join(t_user *this, t_cmd *cmd, t_server *server)
{
	char		**channels;
	char		**keys;
	size_t		index;
	t_channel	*chan;

	channels = init_channels_keys(this, cmd, server, &keys);
	if (!this->connected || channels == NULL)
		return ;
	index = -1;
	while (channels[++index])
	{
		if (!utils_is_valid_channame(channels[index]) || !(chan =
			server_create_or_get_channel(server, channels[index], keys[index])))
			err_nosuchchannel(this, channels[index], server);
		else if (chan->mode.oninv)
			err_inviteonlychan(this, channels[index], server);
		else if (vector_len(chan->users) >= chan->limit)
			err_channelisfull(this, channels[index], server);
		else if ((keys[index] && chan->key && ft_strcmp(chan->key, keys[index]))
				|| (!keys[index] && chan->key != NULL))
			err_badchannelkey(this, channels[index], server);
		else
			channel_new_user(chan, this, server);
	}
	delete_channels_keys(channels, keys);
}
