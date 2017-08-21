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
	((t_user *)data)->msg_nb = 0;
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

static void		iter_del_fn(void *data, void *context)
{
	t_user		*user;
	char		address[INET6_ADDRSTRLEN];

	user = data;
	if (!inet_ntop(AF_INET6, &(user->sin.sin6_addr), address, sizeof(address)))
	{
		server_delete_user(context, user);
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
	server_delete_user(context, user);
}

void			server_ping_timeout(t_server *this)
{
	t_vector	*user_to_del;

	vector_iter(this->users, iter_fn, this);
	user_to_del = vector_find0_all_pop(this->users, find_fn);
	vector_iter(user_to_del, iter_del_fn, this);
	vector_del(user_to_del, NULL);
}
