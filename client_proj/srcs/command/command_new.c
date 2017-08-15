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
#include <ncurses.h>

t_command			*command_new(void)
{
	t_command		*this;
	int				winsize;

	this = ft_calloc(sizeof(t_command));
	this->history = vector_new();
	winsize = COLS;
	if (winsize <= 4)
		this->winsize = 2;
	else
		this->winsize = winsize - 4;
	return (this);
}
