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

t_client			*client_new(char *address, unsigned short port)
{
	t_client		*this;

	this = ft_calloc(sizeof(t_client));
	this->connected = false;
	this->address = address ? ft_strdup(address) : NULL;
	this->port = port;
	this->sock = -1;
	client_try_connect(this);
	client_init_select(this);
	return (this);
}
