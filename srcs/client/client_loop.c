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

static void		inner_loop(t_client *this, fd_set *read_fd)
{
	int		index;
	char	buf[100];
	int		size;

	index = 0;
	while (index < FD_SETSIZE)
	{
		if (FD_ISSET(index, read_fd))
		{
			if ((size = read(index, buf, 15)) == -1)
			{
				ft_perror("read");
				exit(1);
			}
			buf[size] = 0;
			ft_putnbr(size); ft_putchar(' '); ft_putnbr(index);
			ft_putstr(" <"); ft_putstr(buf); ft_putstr(">\n");
			if (size == 0)
				exit(1);
			if (index == 0)
				write(this->sock, buf, size);
		}
		index += 1;
	}
}

void			client_loop(t_client *this)
{
	fd_set	read_fd;

	while (1)
	{
		read_fd = this->active_set;
		if (select(FD_SETSIZE, &read_fd, NULL, NULL, NULL) < 0)
		{
			ft_putstr("Select error toussa\n");
			exit(1);
		}
		inner_loop(this, &read_fd);
	}
}
