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
#include <errno.h>

void			visual_perror(t_visual *this, char *s, char *chan)
{
	t_visual_channel	*channel;

	channel = visual_get_visual_channel(this, chan);
	if (channel == NULL)
	{
		return ;
	}
	wattron(channel->chat, COLOR_PAIR(VIS_COLOR_RED));
	if (s != NULL)
		wprintw(channel->chat, "%s: %s", s, ft_strerror(errno));
	else
		wprintw(channel->chat, "%s", ft_strerror(errno));
}
