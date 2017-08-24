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

static void		invite_with_channel(t_client *this, char **split)
{
	client_write_sock(this, "INVITE ");
	if (split[2])
	{
		client_write_sock(this, split[2]);
	}
	client_write_sock(this, " ");
	client_write_sock(this, split[1]);
	client_write_sock(this, "\r\n");
}

static void		invite_without_channel(t_client *this, char **split)
{
	client_write_sock(this, "INVITE ");
	client_write_sock(this, split[1]);
	client_write_sock(this, " ");
	if (split[2])
	{
		if (split[2][0] != '#' && split[2][0] != '&')
		{
			client_write_sock(this, "#");
		}
		client_write_sock(this, split[2]);
	}
	else
	{
		client_write_sock(this, this->visual->current->name);
	}
	client_write_sock(this, "\r\n");
}

void			client_exec_invite(t_client *this, char *s)
{
	char		**split;

	if (!this->connected)
		return ;
	split = ft_strsplit(s, ' ');
	if (!split)
		return ;
	if (!split[0] || !split[1])
	{
		array_del(split);
		return ;
	}
	if (split[1][0] == '#' || split[1][0] == '&')
		invite_with_channel(this, split);
	else
		invite_without_channel(this, split);
	array_del(split);
}
