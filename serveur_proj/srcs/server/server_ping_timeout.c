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

static void		timeout(t_user *this, t_server *server)
{
	t_query		*query;
	char		address[INET6_ADDRSTRLEN];

	if (!inet_ntop(AF_INET6, &(this->sin.sin6_addr), address, sizeof(address)))
	{
		server_delete_user(server, this);
		return ;
	}
	query = query_new(this);
	if (!this->connected)
	{
		ft_putstr("\033[34;1mregistration timeout from ");
		query->cmd = utils_concat("ERROR: Registration timeout");
	}
	else
	{
		ft_putstr("\033[34;1mping timeout from ");
		query->cmd = utils_concat("ERROR: Ping timeout");
	}
	query->should_quit = true;
	lst_push_front(server->querries, query);
	ft_putstr(address);
	ft_putstr(" (port: ");
	ft_putnbr(this->sin.sin6_port);
	ft_putstr(")\033[0m\n");
}

static void		iter_fn(void *data, void *context)
{
	t_user		*this;
	t_server	*server;
	t_query		*query;

	this = data;
	server = context;
	this->msg_nb = 0;
	if (this->connected && this->timeout == 2)
	{
		query = query_new(this);
		query->cmd = utils_concat("PING :%s", IRC_NAME);
		lst_push_back(server->querries, query);
	}
	this->timeout -= 1;
	if (this->timeout == 0)
		timeout(this, server);
}

void			server_ping_timeout(t_server *this)
{
	vector_iter(this->users, iter_fn, this);
}
