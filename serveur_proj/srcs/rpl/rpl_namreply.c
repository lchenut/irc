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
#include "server.h"
#include "user.h"
#include "channel.h"
#include "xstdlib.h"

static char		*rpl_namreply_concat(char *start, char *end, const char *s)
{
	if (end - start + ft_strlen(s) > 400)
		return (NULL);
	if (start != end)
	{
		*end = ' ';
		end += 1;
	}
	while (*s)
	{
		*end = *s;
		end += 1;
		s += 1;
	}
	*end = 0;
	return (end);
}

void			rpl_namreply(t_user *this, t_channel *channel, t_server *server)
{
	t_vector	*users;
	t_user		*user;
	char		buf[512];
	char		*tmp;
	t_query		*query;

	buf[0] = 0;
	tmp = buf;
	users = vector_copy(channel->users);
	while ((user = vector_pop_back(users)))
	{
		if (!(tmp = rpl_namreply_concat(buf, tmp, user->nick)))
		{
			query = query_new(this);
			query->cmd = utils_concat(":%s 353 %s = %s :%s",
					IRC_NAME, this->nick, channel->name, buf);
			lst_push_back(server->querries, query);
			buf[0] = 0;
			tmp = rpl_namreply_concat(buf, buf, user->nick);
		}
	}
	query = query_new(this);
	query->cmd = utils_concat(":%s 353 %s = %s :%s",
			IRC_NAME, this->nick, channel->name, buf);
	lst_push_back(server->querries, query);
	vector_del(users, NULL);
}
