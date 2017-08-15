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

#include "command.h"

void			command_history_push(t_command *this)
{
	while (vector_len(this->history) > 100)
	{
		line_del(vector_pop_front(this->history));
	}
	if (this->current != this->last)
	{
		line_del(this->last);
		this->last = NULL;
		vector_push_back(this->history, line_copy(this->current));
		line_reset_line(this->current);
		this->current = NULL;
	}
	else
	{
		this->last = NULL;
		vector_push_back(this->history, line_copy(this->current));
		line_del(this->current);
		this->current = NULL;
	}
	this->index = vector_len(this->history);
	this->curspos = 0;
	*((unsigned long *)this->buffer) = 0ul;
}
