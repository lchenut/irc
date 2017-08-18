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
	return (((t_user *)data)->socket == *(int *)context);
}

static bool	find_query(void *data, void *context)
{
	return (((t_query *)data)->user == context);
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

void		server_delete_user_from_socket(t_server *this, int csocket)
{
	t_user	*user;

	if (this == NULL)
		return ;
	user = vector_find_pop(this->users, find_user, &csocket);
	if (user)
	{
		print_address_port(&user->sin);
		lst_clear_if(this->querries, (void(*)(void *))query_del,
				find_query, user);
		user_del(user);
	}
}
