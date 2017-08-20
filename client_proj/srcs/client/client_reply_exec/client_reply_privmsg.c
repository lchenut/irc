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
** TODO message viens d'un channel dans lequel on est pas... pourquoi pas
*/

static void		client_reply_privmsg_user(t_client *this, t_rpl_cnt *content)
{
	t_visual_channel	*channel;
	char				*chan;

	chan = content->nick ? content->nick : content->servername;
	if (!chan)
		return ;
	channel = visual_get_visual_channel(this->visual, chan);
	if (!channel)
	{
		visual_channel_new(this->visual, chan);
		visual_dump_date(this->visual, chan);
		visual_print_bold(this->visual, "Starting query with ", chan);
		visual_print_red(this->visual, chan, chan);
		visual_print_newline(this->visual, chan);
	}
	visual_dump_date(this->visual, chan);
	visual_print_red(this->visual, chan, chan);
	visual_print_red(this->visual, ": ", chan);
	visual_print_channel(this->visual, vector_get_last(content->params), chan);
	visual_print_newline(this->visual, chan);
}

void			client_reply_privmsg(t_client *this, t_rpl_cnt *content,
		const t_reply *reply)
{
	t_visual_channel	*channel;
	char				*chan;

	if (vector_len(content->params) == 2)
	{
		chan = vector_get_first(content->params);
		if (!ft_strcmp(this->nick, chan))
		{
			client_reply_privmsg_user(this, content);
			return ;
		}
		if ((channel = visual_get_visual_channel(this->visual, chan)) == NULL)
		{
			return ;
		}
		visual_dump_date(this->visual, chan);
		visual_print_red(this->visual, content->nick, chan);
		visual_print_red(this->visual, ": ", chan);
		visual_print_channel(this->visual,
				vector_get_last(content->params), chan);
		visual_print_newline(this->visual, chan);
	}
	(void)reply;
}
