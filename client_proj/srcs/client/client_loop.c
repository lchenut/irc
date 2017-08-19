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
#include <errno.h>

void			client_loop(t_client *this)
{
	fd_set		read_fd;
	int			fd;

	while (!this->should_quit)
	{
		read_fd = this->active_set;
		if (select(FD_SETSIZE, &read_fd, NULL, NULL, NULL) < 0)
		{
			if (errno == EINTR)
				continue ;
			break ;
		}
		fd = 0;
		while (fd < FD_SETSIZE)
		{
			if (FD_ISSET(fd, &read_fd))
			{
				if (fd == 0)
					client_read_from_stdin(this);
				else
					client_read_from_socket(this, this->sock);
			}
			fd += 1;
		}
	}
}
