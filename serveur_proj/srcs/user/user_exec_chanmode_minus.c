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

static void		user_exec_chanmode_unset(t_channel *channel, char cmode)
{
	if (cmode == 'p')
		channel_unset_private(channel);
	else if (cmode == 's')
		channel_unset_secret(channel);
	else if (cmode == 'i')
		channel_unset_oninv(channel);
	else if (cmode == 't')
		channel_unset_topiclock(channel);
	else if (cmode == 'n')
		channel_unset_msgrestrict(channel);
	else if (cmode == 'm')
		channel_unset_moderate(channel);
	else if (cmode == 'k')
		channel_unset_key(channel);
}

static void		set_limit(t_channel *channel, t_cmd *cmd, int *i_param)
{
	channel_set_limit(channel, vector_get(cmd->params, *i_param));
	*i_param += 1;
}

static void		del_moderate(t_channel *channel, t_cmd *cmd, int *i_param)
{
	channel_del_moderate(channel, vector_get(cmd->params, *i_param));
	*i_param += 1;
}

void			user_exec_chanmode_minus(t_user *this, t_cmd *cmd,
		t_server *server, t_channel *channel)
{
	char		*mode;
	int			i_mode;
	int			i_param;

	mode = vector_get(cmd->params, 1);
	i_mode = 1;
	i_param = 2;
	while (mode[i_mode] && i_mode < 5)
	{
		if (ft_strchr("psitnmk", mode[i_mode]))
			user_exec_chanmode_unset(channel, mode[i_mode]);
		else if (mode[i_mode] == 'l')
			set_limit(channel, cmd, &i_param);
		else if (mode[i_mode] == 'o')
			channel_del_chanop(channel, this);
		else if (mode[i_mode] == 'v')
			del_moderate(channel, cmd, &i_param);
		else
			err_unknownmode(this, mode[i_mode], server);
		i_mode += 1;
	}
}
