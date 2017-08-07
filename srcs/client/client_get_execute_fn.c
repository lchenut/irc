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

#include "data.h"
#include "client.h"

static bool			find_fn(void *data, void *ctx)
{
	t_command_data	*cmd;

	cmd = data;
	return (!ft_strcmp(cmd->low, ctx) || !ft_strcmp(cmd->upp, ctx));
}

void				(*client_get_execute_fn(char *s))(t_client *, char *)
{
	t_vector		*data;
	t_command_data	*cmd;

	data = data_command();
	cmd = vector_find(data, find_fn, s);
	if (!cmd)
		return (NULL);
	return (cmd->exec_fn);
}
