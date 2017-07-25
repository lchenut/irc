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

char			*buffer_pop_line(t_buffer *this)
{
	size_t		index;
	char		*s;

	index = 0;
	s = this->buffer;
	while (s[index])
	{
		if (s[index] == '\r' && s[index + 1] == '\n')
			break ;
		index += 1;
	}
	if (!s[index])
		return (NULL);
	s = ft_strndup(this->buffer, index);
	ft_memmove(this->buffer, this->buffer + index + 2, this->total - index - 2);
	this->current = this->current - index - 2;
	return (s);
}
