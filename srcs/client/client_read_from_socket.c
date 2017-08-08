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

void			client_read_from_socket(t_client *this, int fd)
{
	char		*rep;

	if (!this->socket_buf)
		this->socket_buf = buffer_new(fd);
	if (!buffer_read_from_fd(this->socket_buf, fd))
	{
		client_disconnect(this);
		return ;
	}
	while ((rep = buffer_pop_line(this->socket_buf)))
	{
		if (rep && !ft_strchr(rep, '\n'))
			buffer_flush_fd(this->socket_buf, fd);
		else if (rep)
			client_print_and_refresh(this, visual_print_chat, rep);
		free(rep);
	}
}
