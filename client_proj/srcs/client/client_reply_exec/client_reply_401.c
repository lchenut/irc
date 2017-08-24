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

void			client_reply_401(t_client *this, t_rpl_cnt *cnt,
		const t_reply *reply)
{
	t_visual_channel	*chan;

	client_reply_pop_params(this, cnt);
	chan = visual_get_visual_channel(this->visual, vector_get(cnt->params, 0));
	if (chan == NULL)
	{
		chan = vector_get_first(this->visual->channels);
		visual_dump_date(this->visual, chan->name);
		visual_print_channel(this->visual, vector_get_last(cnt->params),
				chan->name);
		visual_print_newline(this->visual, chan->name);
	}
	else
	{
		visual_dump_date(this->visual, chan->name);
		visual_print_channel(this->visual, vector_get_last(cnt->params),
				chan->name);
		visual_print_newline(this->visual, chan->name);
		visual_dump_date(this->visual, chan->name);
		visual_print_channel(this->visual, "You should leave the chan "
				"using CTRL-D", chan->name);
		visual_print_newline(this->visual, chan->name);
	}
	visual_move_curspos(this->visual, command_get_curspos(this->command));
	(void)reply;
}
