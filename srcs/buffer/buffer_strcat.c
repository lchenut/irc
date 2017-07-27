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

void			buffer_strcat(t_buffer *this, char *s)
{
	while (*s)
	{
		this->buffer[this->end] = *s;
		this->size += 1;
		s += 1;
		if (this->size == DFL_BUFFER_SIZE)
			break ;
		if (this->end == this->total)
			this->end = 0;
	}
	if (*s)
		this->remainder = ft_strdup(s);
}
