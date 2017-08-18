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

static bool		find_fn(void *data, void *context)
{
	return (data != context);
}

static void		iter_fn(void *data, void *ctx1, void *ctx2)
{
	t_query	*query;

	query = query_new(data);
	query->cmd = ft_strdup(ctx1);
	lst_push_back(((t_server *)ctx2)->querries, query);
}

void			channel_send_msg_from(t_channel *this, t_user *user,
		char *msg, t_server *server)
{
	t_vector	*clone;

	clone = vector_find_all(this->users, find_fn, user);
	vector_iter2(clone, iter_fn, msg, server);
	vector_del(clone, NULL);
}
