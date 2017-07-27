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

t_buffer			*buffer_new(int index)
{
	t_buffer		*this;

	this = ft_calloc(sizeof(t_buffer));
	this->index = index;
	this->buffer = ft_strnew(DFL_BUFFER_SIZE);
	this->total = DFL_BUFFER_SIZE;
	this->start = 0;
	this->end = 0;
	this->size = 0;
	return (this);
}
