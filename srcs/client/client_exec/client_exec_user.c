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

static char		*cli_exe_user_concat(char *src, const char *dst)
{
	while (*dst)
	{
		*src = *dst;
		src += 1;
		dst += 1;
	}
	*src = 0;
	return (src);
}

static void		client_exec_pass_register(t_client *this, struct passwd *pw)
{
	char		buffer[512];
	char		*tmp;

	tmp = cli_exe_user_concat(buffer, "USER ");
	tmp = cli_exe_user_concat(tmp, pw->pw_name);
	tmp = cli_exe_user_concat(buffer, " ");
	tmp = cli_exe_user_concat(tmp, pw->pw_name);
	tmp = cli_exe_user_concat(buffer, " ");
	tmp = cli_exe_user_concat(tmp, this->address);
	tmp = cli_exe_user_concat(buffer, " :");
	tmp = cli_exe_user_concat(tmp, pw->pw_gecos);
	write(this->sock, buffer, buffer - tmp);
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
		client_exec_pass_register(this, pw);
	}
}
