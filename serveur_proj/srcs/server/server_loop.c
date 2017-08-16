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

static void	lol_fn(t_querry *querry, fd_set *set)
{
	if (!FD_ISSET(querry->user->socket, set))
	{
		FD_SET(querry->user->socket, set);
	}
}

void		server_init_fd_set(t_server *this)
{
	FD_ZERO(&this->read_set);
	FD_ZERO(&this->write_set);
	FD_SET(this->socket, &this->read_set);
	vector_iter(this->users, (void(*)(void*, void*))user_fd_set,
			&this->read_set);
	lst_iter(this->querries, (void(*)(void*, void*))lol_fn,
			&this->write_set);
}

static void	print_address_port(struct sockaddr_in6 *sin)
{
	char	address[INET6_ADDRSTRLEN];

	if (!inet_ntop(AF_INET6, &sin->sin6_addr, address, sizeof(address)))
	{
		return ;
	}
	ft_putstr("\033[32maccept from ");
	ft_putstr(address);
	ft_putstr(" (port: ");
	ft_putnbr(sin->sin6_port);
	ft_putstr(")\033[0m\n");
}

void		server_accept(t_server *this)
{
	struct sockaddr_in6	sin;
	unsigned			cslen;
	int					fd;

	bzero(&sin, sizeof(sin));
	cslen = sizeof(sin);
	fd = accept(this->socket, (struct sockaddr *)&sin, &cslen);
	if (fd == -1)
	{
		ft_perror("accept");
		return ;
	}
	print_address_port(&sin);
	vector_push_back(this->users, user_new(fd, &sin));
}

void		server_read_from_user_socket(t_server *this, int csocket)
{
	t_user	*user;
	char	*line;

	user = server_get_user_from_socket(this, csocket);
	if (user == NULL)
		return ;
	if (!buffer_read_from_fd(user->buffer, user->socket))
	{
		server_delete_user_from_socket(this, csocket);
		return ;
	}
	while ((line = buffer_pop_line(user->buffer)))
	{
		if (!ft_strchr(line, '\n'))
		{
			buffer_flush_fd(user->buffer, user->socket);
		}
		else
		{
			user_exec_command(user, line, this);
		}
	}
}

static void	iter_fn(void *data, void *ctx1, void *ctx2)
{
	(void)data;
	(void)ctx1;
	(void)ctx2;
}

static bool	find_fn(void *data, void *context)
{
	return (((t_querry *)data)->user->socket == *((int *)context));
}

void		server_loop(t_server *this)
{
	int		index;
	t_querry	*querry;

	while (1)
	{
		server_init_fd_set(this);
		select(FD_SETSIZE, &this->read_set, &this->write_set, NULL, NULL);
		index = 0;
		while (index < FD_SETSIZE)
		{
			if (FD_ISSET(index, &this->read_set))
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
			if (FD_ISSET(index, &this->write_set))
			{
				querry = lst_find_pop(this->querries, find_fn, &index);
				if (querry)
				{
					ft_putstr_fd(querry->cmd, querry->user->socket);
					free(querry);
				}
			}
			index += 1;
		}
	}
	(void)iter_fn;
}
