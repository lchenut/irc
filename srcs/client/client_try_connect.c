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
	struct protoent		*proto;
	struct sockaddr_in	sin;

	if (!(proto = getprotobyname("ip")))
	{
		ft_perror("getprotobyname");
		exit(1);
	}
	this->sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	if (this->address)
	{
		sin.sin_family = AF_INET;
		sin.sin_port = htons(this->port);
		sin.sin_addr.s_addr = inet_addr(this->address);
		if (!connect(this->sock, (const struct sockaddr *)&sin, sizeof(sin)))
			this->connected = true;
		else
			ft_perror("connect");
	}
}
