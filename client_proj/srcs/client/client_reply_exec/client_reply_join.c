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

/*
** srcs/reply/reply_dump.c         : 29 [INFO-]: >nick: pouet<
** srcs/reply/reply_dump.c         : 30 [INFO-]: >user: pouet<
** srcs/reply/reply_dump.c         : 31 [INFO-]: >host: irc.tinyspeck.com<
** srcs/reply/reply_dump.c         : 33 [INFO-]: >command: JOIN<
** srcs/reply/reply_dump.c         : 17 [INFO-]: >param[0]: #chan1__<
*/

void			client_reply_join(t_client *this, t_rpl_cnt *content,
		const t_reply *reply)
{
	t_visual_channel	*channel;

	client_reply_pop_params(this, content);
	if (content->nick && !ft_strcmp(content->nick, this->nick) &&
			vector_get_first(content->params))
	{
		visual_channel_new(this->visual, vector_get_first(content->params));
	}
	else
	{
		channel = visual_get_visual_channel(this->visual,
				vector_get_first(content->params));
		if (!channel)
			return ;
		visual_dump_date(this->visual, channel->name);
		visual_print_red(this->visual, content->nick, channel->name);
		visual_print_red(this->visual, ": ", channel->name);
		visual_print_channel(this->visual, "@", channel->name);
		visual_print_channel(this->visual, content->nick, channel->name);
		visual_print_channel(this->visual,
				" has joined the channel", channel->name);
		visual_print_newline(this->visual, channel->name);
	}
	(void)reply;
}
