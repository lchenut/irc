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

void			client_exec_privmsg_soft(t_client *this, char *cmd)
{
	t_visual_channel	*channel;

	channel = this->visual->current;
	if (!ft_strcmp(channel->name, " HOME "))
	{
		visual_dump_date(this->visual, " HOME ");
		visual_print_red(this->visual, "Cannot send message in  HOME ", " HOME ");
		visual_print_newline(this->visual, " HOME ");
		return ;
	}
	client_write_sock(this, "PRIVMSG ");
	client_write_sock(this, channel->name);
	client_write_sock(this, " :");
	client_write_sock(this, cmd);
	client_write_sock(this, "\r\n");
	visual_dump_date(this->visual, channel->name);
	visual_print_green(this->visual, this->nick, channel->name);
	visual_print_green(this->visual, ": ", channel->name);
	visual_print_channel(this->visual, cmd, channel->name);
	visual_print_newline(this->visual, channel->name);
}
