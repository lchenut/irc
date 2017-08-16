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

static void		client_exec_user_register(t_client *this, struct passwd *pw)
{
	client_write_sock(this, "USER ");
	client_write_sock(this, pw->pw_name);
	client_write_sock(this, " ");
	client_write_sock(this, pw->pw_name);
	client_write_sock(this, " ");
	client_write_sock(this, this->address);
	client_write_sock(this, " :");
	client_write_sock(this, pw->pw_gecos);
	client_write_sock(this, "\r\n");
}

void			client_exec_user(t_client *this, char *s)
{
	struct passwd	*pw;

	if (!s)
	{
		pw = getpwuid(getuid());
		if (!pw)
		{
			write(this->sock, "USER unknown unknown unkown :unknown\r\n", 38);
			return ;
		}
		client_exec_user_register(this, pw);
	}
}
