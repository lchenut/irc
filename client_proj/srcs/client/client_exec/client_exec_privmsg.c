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
#include "array.h"

static char		*find_msg(char *msg)
{
	while (*msg && *msg != ' ')
		msg += 1;
	while (*msg && *msg == ' ')
		msg += 1;
	while (*msg && *msg != ' ')
		msg += 1;
	while (*msg && *msg == ' ')
		msg += 1;
	return (msg);
}

static void		create_user_chan(t_client *this, char *channame, char *msg)
{
	t_visual_channel	*channel;
	char				**split;
	int					index;

	split = ft_strsplit(channame, ',');
	index = 0;
	while (split[index])
	{
		if (split[index][0] && split[index][0] != '#' && split[index][0] != '&')
		{
			channel = visual_get_visual_channel(this->visual, split[index]);
			if (!channel)
			{
				visual_channel_new(this->visual, split[index]);
				visual_dump_date(this->visual, split[index]);
				visual_print_bold(this->visual, "Starting query with ", split[index]);
				visual_print_red(this->visual, split[index], split[index]);
				visual_print_newline(this->visual, split[index]);
			}
			visual_dump_date(this->visual, split[index]);
			visual_print_green(this->visual, this->nick, split[index]);
			visual_print_green(this->visual, ": ", split[index]);
			visual_print_channel(this->visual, msg, split[index]);
			visual_print_newline(this->visual, split[index]);
		}
		index += 1;
	}
	array_del(split);
}

void			client_exec_privmsg(t_client *this, char *cmd)
{
	char		**split;
	char		*msg;

	if (!this->connected)
		return ;
	split = ft_strsplit(cmd, ' ');
	if (!split)
		return ;
	if (!split[0] || !split[1])
	{
		array_del(split);
		return ;
	}
	msg = find_msg(cmd);
	if (*msg)
		create_user_chan(this, split[1], msg);
	client_write_sock(this, "PRIVMSG ");
	client_write_sock(this, split[1]);
	if (*msg)
	{
		client_write_sock(this, " :");
		client_write_sock(this, msg);
	}
	client_write_sock(this, "\r\n");
	array_del(split);
}
