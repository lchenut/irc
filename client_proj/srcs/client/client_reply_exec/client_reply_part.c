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

void			client_reply_part(t_client *this, t_rpl_cnt *content,
		const t_reply *reply)
{
	t_visual_channel	*chan;

	client_reply_pop_params(this, content);
	if (content->nick && !ft_strcmp(content->nick, this->nick) &&
			vector_get_first(content->params))
	{
		visual_channel_del_by_name(this->visual,
				vector_get_first(content->params));
	}
	else if (content->nick)
	{
		chan = visual_get_visual_channel(this->visual,
				vector_get_first(content->params));
		if (!chan)
			return ;
		visual_dump_date(this->visual, chan->name);
		visual_print_red(this->visual, content->nick, chan->name);
		visual_print_red(this->visual, ": ", chan->name);
		visual_print_channel(this->visual, "@", chan->name);
		visual_print_channel(this->visual, content->nick, chan->name);
		visual_print_channel(this->visual, " has left the channel", chan->name);
		visual_print_newline(this->visual, chan->name);
	}
	visual_move_curspos(this->visual, command_get_curspos(this->command));
	(void)reply;
}
