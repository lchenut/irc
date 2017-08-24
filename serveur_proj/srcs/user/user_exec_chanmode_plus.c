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
#include "cmd.h"
#include "channel.h"

static void		user_exec_chanmode_set(t_channel *channel, char cmode,
		t_cmd *cmd, int *i_p)
{
	if (cmode == 'p')
		channel_set_private(channel);
	else if (cmode == 's')
		channel_set_secret(channel);
	else if (cmode == 'i')
		channel_set_oninv(channel);
	else if (cmode == 't')
		channel_set_topiclock(channel);
	else if (cmode == 'n')
		channel_set_msgrestrict(channel);
	else if (cmode == 'm')
		channel_set_moderate(channel);
	else if (cmode == 'l')
	{
		channel_set_limit(channel, vector_get(cmd->params, *i_p));
		i_p += 1;
	}
}

static int		set_key(t_user *this, t_server *server,
		t_channel *channel, char *nickname)
{
	channel_set_key(channel, this, nickname, server);
	return (1);
}

static int		chanop(t_user *this, t_server *server,
		t_channel *channel, char *nickname)
{
	channel_new_chanop(channel, this, nickname, server);
	return (1);
}

static int		modo(t_user *this, t_server *server,
		t_channel *channel, char *nickname)
{
	channel_new_moderate(channel, this, nickname, server);
	return (1);
}

void			user_exec_chanmode_plus(t_user *this, t_cmd *cmd,
		t_server *server, t_channel *channel)
{
	char		*mode;
	int			i_m;
	int			i_p;

	mode = vector_get(cmd->params, 1);
	i_m = 1;
	i_p = 2;
	while (mode[i_m] && i_m < 5)
	{
		if (ft_strchr("psitnml", mode[i_m]))
			user_exec_chanmode_set(channel, mode[i_m], cmd, &i_p);
		else if (mode[i_m] == 'k')
			i_p += set_key(this, server, channel, vector_get(cmd->params, i_p));
		else if (mode[i_m] == 'o')
			i_p += chanop(this, server, channel, vector_get(cmd->params, i_p));
		else if (mode[i_m] == 'v')
			i_p += modo(this, server, channel, vector_get(cmd->params, i_p));
		else
			err_unknownmode(this, mode[i_m], server);
		i_m += 1;
	}
}
