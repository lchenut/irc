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

void				command_history_up(t_command *this)
{
	if (this->index == 0 || vector_len(this->history) == 0)
	{
		return ;
	}
	this->index -= 1;
	if (this->last == this->current)
	{
		this->current = vector_get_last(this->history);
	}
	else
	{
		this->current = vector_get(this->history, this->index);
	}
	this->curspos = this->current->size;
}
