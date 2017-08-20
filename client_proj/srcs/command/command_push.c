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

void			command_push(t_command *this, char c)
{
	if (!this->last)
	{
		this->last = line_new();
		this->current = this->last;
		this->index = vector_len(this->history);
	}
	if (this->buffer[0] || !ft_isprint(c))
		command_ctrl_mvmt(this, c);
	else
		command_place_letter(this, c);
}
