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

static void		visual_channel_del_void(void *this)
{
	visual_channel_del(this);
}

void			visual_del(t_visual *this)
{
	if (!this)
		return ;
	vector_del(this->channels, visual_channel_del_void);
	delwin(this->prompt);
	delwin(this->border);
	endwin();
	free(this);
}
