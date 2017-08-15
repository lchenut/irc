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

void			command_del_left(t_command *this)
{
	if (this->curspos == 0)
		return ;
	ft_memmove(this->current->line + this->curspos - 1,
			this->current->line + this->curspos,
			this->current->size - this->curspos + 1);
	this->curspos -= 1;
	this->current->size -= 1;
}
