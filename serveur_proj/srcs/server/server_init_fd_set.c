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

static void	fd_write_set_init_fn(t_query *query, fd_set *set)
{
	if (!FD_ISSET(query->user->socket, set))
	{
		FD_SET(query->user->socket, set);
	}
}

void		server_init_fd_set(t_server *this)
{
	FD_ZERO(&this->read_set);
	FD_ZERO(&this->write_set);
	FD_SET(this->socket, &this->read_set);
	vector_iter(this->users, (void(*)(void*, void*))user_fd_set,
			&this->read_set);
	lst_iter(this->querries, (void(*)(void*, void*))fd_write_set_init_fn,
			&this->write_set);
}
