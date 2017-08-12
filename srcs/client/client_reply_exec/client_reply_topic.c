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
#include "visual.h"

void			client_reply_topic(t_client *this,
		t_rpl_cnt *content, const t_reply *reply)
{
	char		*chan;
	char		*topic;

	if ((int)vector_len(content->params) == reply->args_number)
	{
		chan = vector_get_first(content->params);
		topic = vector_get_last(content->params);
		visual_dump_date(this->visual, chan);
		if (!ft_strcmp(reply->command, "332"))
		{
			visual_print_green(this->visual, "Topic: ", chan);
			visual_print_bold(this->visual, topic, chan);
		}
		else
		{
			visual_print_red(this->visual, topic, chan);
		}
		visual_print_newline(this->visual, chan);
	}
	(void)reply;
}
