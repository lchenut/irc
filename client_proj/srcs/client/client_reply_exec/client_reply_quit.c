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

void			client_reply_quit(t_client *this, t_rpl_cnt *content,
		const t_reply *reply)
{
	if (content->nick)
	{
		visual_dump_date(this->visual, " HOME ");
		visual_print_red(this->visual, content->nick, " HOME ");
		visual_print_channel(this->visual, " QUIT: ", " HOME ");
		if (vector_len(content->params) > 0)
		{
			visual_print_channel(this->visual,
					vector_get_first(content->params), " HOME ");
		}
		else
		{
			visual_print_channel(this->visual, "Disconnected", " HOME ");
		}
		visual_print_newline(this->visual, " HOME ");
	}
	(void)reply;
}
