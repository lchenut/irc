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

void			client_exec_quit(t_client *this, char *s)
{
	this->should_quit = true;
	if (!this->connected)
		return ;
	while (s[0] && s[0] != ' ')
		s += 1;
	while (s[0] && s[0] == ' ')
		s += 1;
	if (*s)
	{
		client_write_sock(this, "QUIT :");
		client_write_sock(this, s);
	}
	else
	{
		client_write_sock(this, "QUIT");
	}
	client_write_sock(this, "\r\n");
	client_disconnect(this);
}
