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

static char		*pop_line(t_buffer *this, size_t count)
{
	char		*ret;
	int			index;

	ret = ft_strnew(count);
	index = 0;
	this->size -= count;
	while (count)
	{
		ret[index] = this->buffer[this->start];
		index += 1;
		if ((this->start += 1) == this->total)
			this->start = 0;
		count -= 1;
	}
	return (ret);
}

char			*buffer_pop_line(t_buffer *this)
{
	size_t		index;
	size_t		count;

	index = this->start;
	count = 0;
	while (this->buffer[index] != '\n' && count != this->size)
	{
		index += 1;
		count += 1;
		if (index == this->total)
			index = 0;
	}
	if (this->buffer[index] != '\n' && count < this->total)
		return (NULL);
	if (this->buffer[index] == '\n' && count == this->size)
		return (NULL);
	return (pop_line(this, this->buffer[index] != '\n' ? count : count + 1));
}
