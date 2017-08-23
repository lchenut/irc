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
#include "user.h"
#include "server.h"

static void	concat_mode(char *m, int *index, char c)
{
	m[*index] = c;
	*index += 1;
}

static void	create_mode(char *m, t_channel *channel)
{
	int		index;

	index = 0;
	if (channel->mode.private)
		concat_mode(m, &index, 'p');
	if (channel->mode.secret)
		concat_mode(m, &index, 's');
	if (channel->mode.oninv)
		concat_mode(m, &index, 'i');
	if (channel->mode.topiclock)
		concat_mode(m, &index, 't');
	if (channel->mode.msgrestrict)
		concat_mode(m, &index, 'n');
	if (channel->mode.moderate)
		concat_mode(m, &index, 'm');
	m[index] = 0;
}

void		rpl_channelmodeis(t_user *this, t_channel *channel,
		char *mode_param, t_server *server)
{
	// TODO mode param == list des params, pas juste le premier
	t_query	*query;
	char	m[64];

	create_mode(m, channel);
	query = query_new(this);
	if (m[0] == 0 && !mode_param)
		query->cmd = utils_concat(":%s 324 %s", IRC_NAME, channel->name);
	else if (m[0] == 0 && mode_param)
		query->cmd = utils_concat(":%s 324 %s :%s", IRC_NAME, channel->name, mode_param);
	else if (!mode_param)
		query->cmd = utils_concat(":%s 324 %s %s", IRC_NAME, channel->name, m);
	else
		query->cmd = utils_concat(":%s 324 %s %s :%s",
				IRC_NAME, channel->name, m, mode_param);
	lst_push_back(server->querries, query);
}
