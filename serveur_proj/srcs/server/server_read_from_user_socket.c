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

static void	server_read_loop(t_server *this, t_user *user)
{
	char	*line;

	while ((line = buffer_pop_line(user->buffer)))
	{
		if (!ft_strchr(line, '\n'))
		{
			user->flush_sock = true;
			break ;
		}
		else
		{
			user_exec_command(user, line, this);
		}
	}
}

void		server_read_from_user_socket(t_server *this, int csocket)
{
	t_user	*user;
	int		flush_ret;

	user = server_get_user_from_socket(this, csocket);
	if (user == NULL)
		return ;
	if (user->flush_sock)
	{
		flush_ret = buffer_flush_fd(user->buffer, user->socket);
		if (flush_ret <= 0)
		{
			server_delete_user_from_socket(this, csocket);
			return ;
		}
		else if (flush_ret == 1)
			user->flush_sock = false;
		else
			return ;
	}
	else if (!buffer_read_from_fd(user->buffer, user->socket))
	{
		server_delete_user_from_socket(this, csocket);
		return ;
	}
	server_read_loop(this, user);
}
