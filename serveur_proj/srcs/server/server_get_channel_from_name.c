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

static bool			find_fn(void *data, void *context)
{
	char			*chan;
	char			*name;

	chan = ((t_channel *)data)->name;
	name = context;
	while (*chan || *name)
	{
		if (ft_toupper(*chan) != ft_toupper(*name))
			return (false);
		chan += 1;
		name += 1;
	}
	return (true);
}

t_channel			*server_get_channel_from_name(t_server *this, char *name)
{
	return (vector_find(this->channels, find_fn, name));
}
