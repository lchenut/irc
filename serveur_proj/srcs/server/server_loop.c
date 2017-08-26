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

#include <time.h>
#include "server.h"

static void	read_fd_isset(t_server *this, int index)
{
	if (index == this->socket)
	{
		server_accept(this);
	}
	else
	{
		server_read_from_user_socket(this, index);
	}
}

static bool	find_fn(void *data, void *context)
{
	return (((t_query *)data)->user->socket == *((int *)context));
}

static void	write_fd_isset(t_server *this, int index)
{
	t_query	*query;

	query = lst_find_pop(this->querries, find_fn, &index);
	if (query)
	{
		printf("Send to %s: %s", query->user->nick, query->cmd);
		ft_putstr_fd(query->cmd, query->user->socket);
		if (query->should_quit)
		{
			user_exec_quit_from_query(query->user, query, this);
			// server_delete_user(this, query->user);
		}
		query_del(query);
	}
}

static int	server_select(t_server *this)
{
	struct timeval	tv;
	time_t			t;
	time_t			i;

	t = time(NULL);
	i = 1;
	while ((t + i) % 60)
	{
		i += 1;
	}
	tv.tv_sec = i;
	tv.tv_usec = 0;
	return (select(FD_SETSIZE, &this->read_set, &this->write_set, NULL, &tv));
}

void		server_loop(t_server *this)
{
	int		index;
	int		select_ret;

	while (1)
	{
		server_init_fd_set(this);
		select_ret = server_select(this);
		if (select_ret == -1)
			break ;
		if (select_ret == 0)
		{
			server_ping_timeout(this);
			continue ;
		}
		index = 0;
		while (index < FD_SETSIZE)
		{
			if (FD_ISSET(index, &this->read_set))
				read_fd_isset(this, index);
			if (FD_ISSET(index, &this->write_set))
				write_fd_isset(this, index);
			index += 1;
		}
	}
}
