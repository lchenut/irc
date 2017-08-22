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
** TODO: Message d'erreur en cas de non connection
*/

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

static void		topic_two_args(t_client *this, char *s)
{
	char		*chan;
	char		*message;

	get_chan_and_message(s, &chan, &message);
	if (!*chan)
	{
		client_write_sock(this, "TOPIC\r\n");
		return ;
	}
	if (*chan != '#' && *chan != '&')
	{
		chan -= 1;
		*chan = '#';
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

void			client_exec_topic(t_client *this, char *s)
{
	char		*chan;

	if (!this->connected)
		return ;
	chan = this->visual->current->name;
	if (*chan != '#' && *chan != '&')
		topic_two_args(this, s);
	else
	{
		while (s[0] && s[0] != ' ')
			s += 1;
		while (s[0] && s[0] == ' ')
			s += 1;
		client_write_sock(this, "TOPIC ");
		client_write_sock(this, chan);
		if (*s)
		{
			client_write_sock(this, " :");
			client_write_sock(this, s);
		}
		client_write_sock(this, "\r\n");
	}
}
