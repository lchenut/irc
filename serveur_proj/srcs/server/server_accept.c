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

static void	print_address_port(struct sockaddr_in6 *sin)
{
	char	address[INET6_ADDRSTRLEN];

	if (!inet_ntop(AF_INET6, &sin->sin6_addr, address, sizeof(address)))
	{
		return ;
	}
	ft_putstr("\033[32maccept from ");
	ft_putstr(address);
	ft_putstr(" (port: ");
	ft_putnbr(sin->sin6_port);
	ft_putstr(")\033[0m\n");
}

void		server_accept(t_server *this)
{
	struct sockaddr_in6	sin;
	unsigned			cslen;
	int					fd;

	bzero(&sin, sizeof(sin));
	cslen = sizeof(sin);
	fd = accept(this->socket, (struct sockaddr *)&sin, &cslen);
	if (fd == -1)
	{
		ft_perror("accept");
		return ;
	}
	print_address_port(&sin);
	vector_push_back(this->users, user_new(fd, &sin));
}
