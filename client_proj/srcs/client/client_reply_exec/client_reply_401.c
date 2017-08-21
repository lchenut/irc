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

void			client_reply_401(t_client *this, t_rpl_cnt *content,
		const t_reply *reply)
{
	t_visual_channel	*channel;

	client_reply_pop_params(this, content);
	channel = visual_get_visual_channel(this->visual,
			vector_get_first(content->params));
	if (channel == NULL)
	{
		channel = vector_get_first(this->visual->channels);
		visual_dump_date(this->visual, channel->name);
		visual_print_channel(this->visual, vector_get_last(content->params),
				channel->name);
		visual_print_newline(this->visual, channel->name);
	}
	else
	{
		visual_dump_date(this->visual, channel->name);
		visual_print_channel(this->visual, vector_get_last(content->params),
				channel->name);
		visual_print_newline(this->visual, channel->name);
		visual_dump_date(this->visual, channel->name);
		visual_print_channel(this->visual, "You should leave the channel "
				"using CTRL-D", channel->name);
		visual_print_newline(this->visual, channel->name);
	}
	visual_move_curspos(this->visual, command_get_curspos(this->command));
	(void)reply;
}
