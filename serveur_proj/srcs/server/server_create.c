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

static bool		server_init_and_continue(t_server *this)
{
	struct protoent		*pe;
	int					opt;

	if (!(pe = getprotobyname("tcp")))
	{
		this->err_msg = "getprotobyname";
		return (false);
	}
	if ((this->socket = socket(PF_INET6, SOCK_STREAM, pe->p_proto)) == -1)
	{
		this->err_msg = "socket";
		return (false);
	}
	opt = 1;
	if (setsockopt(this->socket, SOL_SOCKET,
				SO_REUSEADDR, &opt, sizeof(int)) == -1)
	{
		this->err_msg = "setsockopt";
		close(this->socket);
		return (false);
	}
	return (true);
}

void			server_create(t_server *this)
{
	struct sockaddr_in6	sin;

	if (!server_init_and_continue(this))
		return ;
	ft_bzero(&sin, sizeof(struct sockaddr_in6));
	sin.sin6_family = AF_INET6;
	sin.sin6_addr = in6addr_any;
	sin.sin6_port = htons(this->port);
	if (bind(this->socket, (struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		close(this->socket);
		this->err_msg = "bind";
		return ;
	}
	if (listen(this->socket, 50) == -1)
	{
		close(this->socket);
		this->err_msg = "listen";
	}
	this->connected = true;
}
