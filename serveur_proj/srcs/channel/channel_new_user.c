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
#include "server.h"

static void		iter_fn(void *data, void *ctx1, void *ctx2)
{
	t_querry	*querry;

	querry = querry_new(data);
	querry->cmd = ft_strdup(ctx1);
	lst_push_back(((t_server *)ctx2)->querries, querry);
}

void			channel_new_user(t_channel *this, t_user *user,
		t_server *server)
{
	char		cmd[512];
	char		*tmp;

	vector_push_back(this->users, user);
	*cmd = 0;
	tmp = utils_concat(cmd, ":");
	tmp = utils_concat(tmp, user->nick);
	tmp = utils_concat(tmp, "!");
	tmp = utils_concat(tmp, user->user);
	tmp = utils_concat(tmp, "@");
	tmp = utils_concat(tmp, IRC_NAME);
	tmp = utils_concat(tmp, " JOIN ");
	tmp = utils_concat(tmp, this->name);
	tmp = utils_concat(tmp, "\r\n");
	vector_iter2(this->users, iter_fn, cmd, server);
	if (this->topic)
		rpl_topic(user, this, server);
	else
		rpl_notopic(user, this, server);
}
