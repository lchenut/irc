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

static void		client_exec_nick_register(t_client *this)
{
	char		*buffer;
	char		*tmp;
	size_t		index;

	buffer = malloc(ft_strlen(this->nick) + 10);
	index = 0;
	while ("NICK "[index])
	{
		buffer[index] = "NICK "[index];
		index += 1;
	}
	tmp = this->nick;
	while (*tmp)
	{
		buffer[index] = *tmp;
		index += 1;
		tmp += 1;
	}
	buffer[index] = '\r';
	buffer[index + 1] = '\n';
	write(this->sock, buffer, index + 2);
	free(buffer);
}

void			client_exec_nick(t_client *this, char *s)
{
	struct passwd	*pw;

	if (!s)
	{
		if (!this->nick)
		{
			pw = getpwuid(getuid());
			client_set_nick(this, (pw) ? pw->pw_name : "unknown");
		}
		client_exec_nick_register(this);
	}
	// TODO: le reste :3
}
