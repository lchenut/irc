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
	if (((t_user *)data)->nick == NULL)
		return (false);
	return (ft_strcmp(((t_user *)data)->nick, context) == 0);
}

t_user		*server_get_user_from_nick(t_server *this, char *nick)
{
	if (this == NULL || nick == NULL)
		return (NULL);
	return (vector_find(this->users, find_fn, nick));
}
