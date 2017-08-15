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
#include <sys/types.h>
#include <sys/uio.h>

int				buffer_read_from_fd(t_buffer *this, int fd)
{
	int			read_ret;
	int			size;

	size = (this->end < this->start) ?
		this->start - this->end : this->total - this->end;
	read_ret = read(fd, this->buffer + this->end, size);
	if (read_ret <= 0)
		return (read_ret);
	this->size += read_ret;
	if (this->end + read_ret == this->total)
		this->end = 0;
	else
		this->end += read_ret;
	return (read_ret);
}
