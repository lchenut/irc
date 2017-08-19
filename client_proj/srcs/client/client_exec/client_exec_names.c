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
#include "array.h"

/*
** TODO: Plus propre (exec_names_with_arg) (regarder exec_list_with_arg)
** TODO: Message d'erreur en cas de non connection
*/

static void		exec_names_without_arg(t_client *this)
{
	char		*name;

	name = this->visual->current->name;
	if (name[0] == '#' || name[0] == '&')
	{
		client_write_sock(this, "NAMES ");
		client_write_sock(this, name);
		client_write_sock(this, "\r\n");
	}
	else
	{
		client_write_sock(this, "NAMES\r\n");
	}
}

static void		exec_names_with_arg(t_client *this, char *channels)
{
	char		**split;
	int			index;

	split = ft_strsplit(channels, ',');
	index = 0;
	client_write_sock(this, "NAMES ");
	while (split[index])
	{
		if (index > 0)
			client_write_sock(this, ",");
		if (split[index][0] != '#' && split[index][0] != '&')
			client_write_sock(this, "#");
		client_write_sock(this, split[index]);
		index += 1;
	}
	client_write_sock(this, "\r\n");
}

void			client_exec_names(t_client *this, char *cmd)
{
	char		**split;

	if (!this->connected)
		return ;
	split = ft_strsplit(cmd, ' ');
	if (!split)
		return ;
	if (split[0] && !split[1])
	{
		exec_names_without_arg(this);
	}
	else if (split[0] && split[1])
	{
		exec_names_with_arg(this, split[1]);
	}
	array_del(split);
}
