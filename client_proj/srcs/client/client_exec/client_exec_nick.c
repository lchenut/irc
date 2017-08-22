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
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>

/*
** TODO: le rename
*/

static void		client_exec_nick_register(t_client *this)
{
	char		buffer[512];
	char		*tmp;
	size_t		index;

	index = 0;
	while ("NICK "[index])
	{
		buffer[index] = "NICK "[index];
		index += 1;
	}
	tmp = this->nick;
	while (*tmp && index < 510)
	{
		buffer[index] = *tmp;
		index += 1;
		tmp += 1;
	}
	buffer[index] = 0;
	client_write_sock(this, buffer);
	client_write_sock(this, "\r\n");
}

static void		client_exec_change_nick(t_client *this, char *s)
{
	char		*new_nick;

	while (*s && *s != ' ')
		s += 1;
	while (*s && *s == ' ')
		s += 1;
	if (!*s)
	{
		client_write_sock(this, "NICK\r\n");
		return ;
	}
	new_nick = s;
	while (*s && *s != ' ')
		s += 1;
	s = 0;
	client_write_sock(this, "NICK ");
	client_write_sock(this, new_nick);
	client_write_sock(this, "\r\n");
}

void			client_exec_nick(t_client *this, char *s)
{
	struct passwd	*pw;

	if (!s)
	{
		if (!this->nick || !*this->nick)
		{
			pw = getpwuid(getuid());
			client_set_nick(this, (pw) ? pw->pw_name : "unknown");
		}
		client_exec_nick_register(this);
	}
	else
	{
		client_exec_change_nick(this, s);
	}
}
