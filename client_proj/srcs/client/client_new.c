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

t_client			*client_new(void)
{
	t_client		*this;

	this = ft_calloc(sizeof(t_client));
	this->connected = false;
	this->serv_connect = false;
	client_set_port(this, DFL_SERVER_PORT);
	this->sock = -1;
	this->should_quit = false;
	this->visual = visual_new();
	this->command = command_new();
	this->socket_buf = buffer_new();
	this->flush_sock = false;
	FD_ZERO(&(this->active_set));
	FD_SET(0, &(this->active_set));
	return (this);
}
