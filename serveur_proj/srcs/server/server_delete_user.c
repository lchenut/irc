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

static bool	find_user(void *data, void *context)
{
	return (data == context);
}

static void	print_address_port(struct sockaddr_in6 *sin)
{
	char	address[INET6_ADDRSTRLEN];

	if (!inet_ntop(AF_INET6, &sin->sin6_addr, address, sizeof(address)))
	{
		return ;
	}
	ft_putstr("\033[31mlogout from ");
	ft_putstr(address);
	ft_putstr(" (port: ");
	ft_putnbr(sin->sin6_port);
	ft_putstr(")\033[0m\n");
}

void		server_delete_user(t_server *this, t_user *user)
{
	if (this == NULL)
		return ;
	if (user)
	{
		print_address_port(&user->sin);
		vector_find_pop(this->users, find_user, user);
		server_clear_user_querries(this, user);
		server_clear_user_cmd_lst(this, user);
		vector_iter(this->channels,
				(void(*)(void *, void *))channel_del_user, user);
		user_del(user);
	}
}
