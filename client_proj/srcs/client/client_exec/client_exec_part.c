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

/*
** TODO: Message d'erreur en cas de non connection
*/

static void	exec_part_current_channel(t_client *this)
{
	char	*current;

	current = this->visual->current->name;
	if (*current == '#' || *current == '&')
	{
		client_write_sock(this, "PART ");
		client_write_sock(this, current);
		client_write_sock(this, "\r\n");
	}
	else
	{
		client_write_sock(this, "PART\r\n");
	}
}

static void	exec_part_args(t_client *this, char *s)
{
	char	buffer[512];
	size_t	index;

	client_write_sock(this, "PART ");
	while (*s)
	{
		index = 0;
		while (*s && *s == ',')
			s += 1;
		while (s[index] && s[index] != ',')
		{
			buffer[index] = s[index];
			index += 1;
		}
		buffer[index] = 0;
		if (buffer[0] && buffer[0] != '#' && buffer[0] != '&')
			client_write_sock(this, "#");
		if (buffer[0])
			client_write_sock(this, buffer);
		if (buffer[0] && s[index])
			client_write_sock(this, ",");
		s += index;
	}
	client_write_sock(this, "\r\n");
}

void		client_exec_part(t_client *this, char *s)
{
	if (!this->connected)
		return ;
	while (*s && *s != ' ')
		s += 1;
	while (*s && *s == ' ')
		s += 1;
	if (!*s)
	{
		exec_part_current_channel(this);
	}
	else
	{
		exec_part_args(this, s);
	}
}
