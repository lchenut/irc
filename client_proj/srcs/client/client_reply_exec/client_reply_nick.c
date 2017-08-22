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

static void		change_name(t_client *this, t_rpl_cnt *content, char *channame)
{
	visual_dump_date(this->visual, channame);
	visual_print_red(this->visual, content->nick, channame);
	visual_print_channel(this->visual, " is now known as ", channame);
	visual_print_channel(this->visual,
			vector_get_first(content->params), channame);
	visual_print_newline(this->visual, channame);
}

void			client_reply_nick(t_client *this, t_rpl_cnt *content,
		const t_reply *reply)
{
	t_visual_channel	*channel;

	if (content->nick && vector_len(content->params) > 0)
	{
		if (this->nick && ft_strcmp(content->nick, this->nick) == 0)
		{
			client_set_nick(this, vector_get_first(content->params));
		}
		change_name(this, content, " HOME ");
		channel = visual_get_visual_channel(this->visual, content->nick);
		if (channel)
		{
			change_name(this, content, channel->name);
			visual_channel_rename(this->visual, content->nick,
					vector_get_first(content->params));
		}
	}
	(void)reply;
}
