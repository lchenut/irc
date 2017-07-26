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

#include "client.h"

void					client_try_connect(t_client *this)
{
	struct addrinfo		*info;
	struct addrinfo		hint;
	int					gai_error;

	if (!this->address)
		return ;
	hint.ai_family = AF_UNSPEC;
	hint.ai_socktype = SOCK_STREAM;
	gai_error = getaddrinfo(this->address, this->port, &hint, &info);
	if (gai_error)
		return ; // TODO: L'utilisateur a fait de la merde... si == 8
	if (info->ai_family == AF_INET)
		client_try_connect_ipv4(this, info);
	else if (info->ai_family == AF_INET6)
		client_try_connect_ipv6(this, info);
	else
		return ; // TODO: C'est chelou !
}
