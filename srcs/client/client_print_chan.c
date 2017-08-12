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

#include "client.h"

void			client_print_chan(t_client *this,
		void (*fn)(t_visual *, char *, char *), char *msg, char *chan)
{
	if (fn != NULL)
	{
		visual_dump_date(this->visual, chan);
		fn(this->visual, msg, chan);
		visual_print_newline(this->visual, chan);
	}
	if (this->command)
	{
		visual_print_prompt(this->visual,
			command_get_line_scaled(this->command));
		visual_move_curspos(this->visual, command_get_curspos(this->command));
	}
}
