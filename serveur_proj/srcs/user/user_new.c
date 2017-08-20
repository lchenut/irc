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

#include "user.h"

t_user			*user_new(int socket, struct sockaddr_in6 *sin)
{
	t_user		*this;

	this = ft_calloc(sizeof(t_user));
	this->nick = NULL;
	this->socket = socket;
	this->buffer = buffer_new();
	this->timeout = 2;
	this->connected = false;
	this->flush_sock = false;
	ft_memmove(&this->sin, sin, sizeof(struct sockaddr_in6));
	return (this);
}
