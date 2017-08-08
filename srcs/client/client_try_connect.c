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
#include "utils.h"

static void				client_address_error(t_client *this, int error)
{
	char				*err;

	err = utils_gai_strerror(error);
	client_print_and_refresh(this, visual_gaierror, err);
}

void					client_try_connect(t_client *this)
{
	struct addrinfo		*info;
	int					gai_error;

	if (!this->address)
		return ;
	LOG_INFO("Try connect to: %s:%s", this->address, this->port);
	gai_error = getaddrinfo(this->address, this->port, NULL, &info);
	if (gai_error)
	{
		client_address_error(this, gai_error);
		return ;
	}
	if (info->ai_family == AF_INET)
		client_try_connect_ipv4(this, info);
	else if (info->ai_family == AF_INET6)
		client_try_connect_ipv6(this, info);
	else
		client_address_error(this, 8);

}
