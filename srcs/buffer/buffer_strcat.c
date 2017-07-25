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
	size_t		new_string_length;

	new_string_length = ft_strlen(s);
	while (new_string_length + this->current > this->total)
		buffer_realloc(this);
	ft_strcat(this->buffer, s);
	this->current += new_string_length;
}
