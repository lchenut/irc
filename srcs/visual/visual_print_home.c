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

void			visual_print_home(t_visual *this, char *buf)
{
	wprintw(((t_visual_channel *)vector_get_first(this->channels))->chat,
			"%s\n", buf);
	if (vector_get_first(this->channels) == this->current)
	{
		wrefresh(this->current->chat);
	}
}
