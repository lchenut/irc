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

static bool	find_user(void *data, void *context)
{
	return (data == context);
}

void		server_delete_user(t_server *this, t_user *user)
{
	if (this == NULL)
		return ;
	if (user)
	{
		vector_find_pop(this->users, find_user, user);
		server_clear_user_querries(this, user);
		server_clear_user_cmd_lst(this, user);
		vector_iter(this->channels,
				(void(*)(void *, void *))channel_del_user, user);
		user_del(user);
	}
}
