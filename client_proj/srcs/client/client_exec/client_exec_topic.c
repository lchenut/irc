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

static void		get_chan_and_message(char *s, char **chan, char **message)
{
	while (s[0] && s[0] != ' ')
		s += 1;
	while (s[0] && s[0] == ' ')
		s += 1;
	*chan = s;
	while (*s && *s != ' ')
		s += 1;
	if (*s != 0)
	{
		*s = 0;
		s += 1;
		while (*s && *s == ' ')
			s += 1;
	}
	*message = s;
}

void			client_exec_topic(t_client *this, char *s)
{
	char		*chan;
	char		*message;

	if (!this->connected)
		return ; // TODO: Message d'erreur
	get_chan_and_message(s, &chan, &message);
	if (*chan != '#' && *chan != '&')
	{
		chan -= 1;
		*chan = '#';
	}
	if (!visual_get_visual_channel(this->visual, chan))
	{
		visual_dump_date(this->visual, "HOME");
		visual_print_red(this->visual, "There no such channel: ", "HOME");
		visual_print_red(this->visual, chan, "HOME");
		visual_print_newline(this->visual, "HOME");
		return ;
	}
	client_write_sock(this, "TOPIC ");
	client_write_sock(this, chan);
	if (*message)
	{
		client_write_sock(this, " :");
		client_write_sock(this, message);
	}
	client_write_sock(this, "\r\n");
}
