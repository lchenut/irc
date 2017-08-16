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

t_server		*server_new(void)
{
	t_server	*this;

	this = ft_calloc(sizeof(t_server));
	this->port = -1;
	this->connected = false;
	this->err_msg = NULL;
	this->maxchannels = 100;
	this->users = vector_new();
	this->channels = vector_new();
	this->querries = lst_new();
	return (this);
}
