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
	char		buffer[512];
	char		*tmp;

	tmp = utils_concat(buffer, "USER ");
	tmp = utils_concat(tmp, pw->pw_name);
	tmp = utils_concat(tmp, " ");
	tmp = utils_concat(tmp, pw->pw_name);
	tmp = utils_concat(tmp, " ");
	tmp = utils_concat(tmp, this->address);
	tmp = utils_concat(tmp, " :");
	tmp = utils_concat(tmp, pw->pw_gecos);
	tmp = utils_concat(tmp, "\r\n");
	write(this->sock, buffer, tmp - buffer);
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
