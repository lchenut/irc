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

void			visual_perror(t_visual *this, char *s)
{
	wattron(this->chat, COLOR_PAIR(40));
	if (s != NULL)
	{
		waddstr(this->chat, s);
		waddstr(this->chat, ": ");
	}
	waddstr(this->chat, ft_strerror(errno));
	wattroff(this->chat, COLOR_PAIR(40));
	waddch(this->chat, '\n');
	wrefresh(this->chat);
}
