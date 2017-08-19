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

static bool		exists_fn(void *data, void *context)
{
	return (data == context);
}

static void		iter_fn(void *data, void *ctx1, void *ctx2)
{
	t_query	*query;

	query = query_new(data);
	query->cmd = ft_strdup(ctx1);
	lst_push_back(((t_server *)ctx2)->querries, query);
}

void			channel_new_user(t_channel *this, t_user *user,
		t_server *server)
{
	char		*cmd;

	if (vector_exists(this->users, exists_fn, user))
		return ;
	vector_push_back(this->users, user);
	cmd = utils_concat(":%s!%s@%s JOIN %s", user->nick, user->user, IRC_NAME,
			this->name);
	vector_iter2(this->users, iter_fn, cmd, server);
	free(cmd);
	if (this->topic)
		rpl_topic(user, this, server);
	else
		rpl_notopic(user, this, server);
}
