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

static bool	find_fn(void *data, void *context)
{
	return (((t_user *)data)->socket == *(int *)context);
}

t_user		*server_get_user_from_socket(t_server *this, int csocket)
{
	if (this == NULL)
		return (NULL);
	return (vector_find(this->users, find_fn, &csocket));
}
