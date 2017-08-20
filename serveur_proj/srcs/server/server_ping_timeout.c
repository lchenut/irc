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

#include "server.h"

static void		exec_ping(t_user *this, t_server *server)
{
	t_query		*query;

	query = query_new(this);
	query->cmd = utils_concat("PING :%s", IRC_NAME);
	lst_push_back(server->querries, query);
}

static void		iter_fn(void *data, void *context)
{
	if (((t_user *)data)->connected && ((t_user *)data)->timeout == 2)
	{
		exec_ping(data, context);
	}
	((t_user *)data)->timeout -= 1;
}

static bool		find_fn(void *data)
{
	return (((t_user *)data)->timeout == 0);
}

static void		del_fn(void *data)
{
	t_user		*user;
	char		address[INET6_ADDRSTRLEN];

	user = data;
	if (!inet_ntop(AF_INET6, &(user->sin.sin6_addr), address, sizeof(address)))
	{
		user_del(user);
		return ;
	}
	if (!user->connected)
	{
		ft_putstr("\033[34;1mregistration timeout from ");
		write(user->socket, "ERROR: Registration timeout\r\n", 29);
	}
	else
	{
		ft_putstr("\033[34;1mping timeout from ");
		write(user->socket, "ERROR: Ping timeout\r\n", 21);
	}
	ft_putstr(address);
	ft_putstr(" (port: ");
	ft_putnbr(user->sin.sin6_port);
	ft_putstr(")\033[0m\n");
	user_del(user);
}

void			server_ping_timeout(t_server *this)
{
	vector_iter(this->users, iter_fn, this);
	vector_del(vector_find0_all_pop(this->users, find_fn), del_fn);
}
