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

void				client_try_connect_ipv4(t_client *this,
		struct addrinfo *info)
{
	struct protoent	*proto;

	client_try_connect_log(this, AF_INET);
	if (!(proto = getprotobyname("ip")))
	{
		this->should_quit = true;
		this->quit_msg = "Bad protocol";
		return ;
	}
	this->sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	if (!connect(this->sock, info->ai_addr, sizeof(struct sockaddr_in)))
	{
		client_print_and_refresh(this, visual_print_green, "Connected");
		FD_SET(this->sock, &this->active_set);
		this->connected = true;
	}
	else
	{
		close(this->sock);
		this->sock = -1;
		client_print_and_refresh(this, visual_perror, "connect");
	}
}
