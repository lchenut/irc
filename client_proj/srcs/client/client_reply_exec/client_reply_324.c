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

void			client_reply_324(t_client *this, t_rpl_cnt *content,
		const t_reply *reply)
{
	t_visual_channel	*channel;
	char				*channame;

	channame = vector_get_first(content->params);
	if (channame == NULL)
		return ;
	channel = visual_get_visual_channel(this->visual, channame);
	if (channel == NULL)
	{
		channel = vector_get_first(this->visual->channels);
	}
	visual_dump_date(this->visual, channel->name);
	visual_print_green(this->visual, "Mode ", channel->name);
	visual_print_green(this->visual, channame, channel->name);
	visual_print_green(this->visual, ": ", channel->name);
	if (vector_get(content->params, 1))
		visual_print_bold(this->visual,
				vector_get(content->params, 1), channel->name);
	visual_print_newline(this->visual, channel->name);
	(void)reply;
}
