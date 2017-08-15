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

#include "visual.h"

void			visual_chat_decr(t_visual *this)
{
	if (this->index == 0)
	{
		this->index = vector_len(this->channels) - 1;
	}
	else
	{
		this->index = (this->index - 1) % vector_len(this->channels);
	}
	this->current = vector_get(this->channels, this->index);
	visual_print_border(this);
	redrawwin(this->current->chat);
	wrefresh(this->current->chat);
}
