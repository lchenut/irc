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

#include "buffer.h"

int				buffer_flush_fd(t_buffer *this, int fd)
{
	int			read_ret;
	size_t		index;

	read_ret = read(fd, this->buffer, DFL_BUFFER_SIZE);
	if (read_ret <= 0)
		return (read_ret);
	index = 0;
	while (this->buffer[index] != '\n' && index < (size_t)read_ret)
		index += 1;
	if (this->buffer[index] == '\n')
	{
		index += 1;
		if (read_ret == (int)this->total && read_ret == (int)index)
			this->start = 0;
		else
			this->start = index;
		this->end = ((size_t)read_ret == this->total) ? 0 : read_ret;
		this->size = read_ret - index;
		return (1);
	}
	return (2);
}
