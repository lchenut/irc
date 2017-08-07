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

void					client_try_connect_ipv4(t_client *this,
		struct addrinfo *info)
{
	struct protoent		*proto;

	if (!(proto = getprotobyname("ip")))
	{
		ft_perror("getprotobyname");
		exit(1); // TODO: quitter plus proprement
	}
	this->sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	if (!connect(this->sock, info->ai_addr, sizeof(struct sockaddr_in)))
		this->connected = true;
	else
		client_print_and_refresh(this, visual_perror, "connect");
}
