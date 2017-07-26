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
#define CLIENT_READ_FROM_SOCKET_BUFFER_SIZE 64

void			client_read_from_socket(t_client *this, int fd)
{
	char		buf[CLIENT_READ_FROM_SOCKET_BUFFER_SIZE];
	char		*s;
	int			size;

	size = read(fd, buf, CLIENT_READ_FROM_SOCKET_BUFFER_SIZE - 1);
	if (size == -1)
	{
		ft_perror("read");
		exit(1);
	}
	if (size == 0)
	{
		exit(0); // TODO: 13:16 -!- Irssi: Connection lost to 127.0.0.1
	}
	buf[size] = 0;
	ft_putendl(buf);
	if (!this->socket_buf)
		this->socket_buf = buffer_new(fd);
	buffer_strcat(this->socket_buf, buf);
	while ((s = buffer_pop_line(this->socket_buf)))
		ft_putendl(s);
}
