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

static char		*fill_buffer(char *start, char *end, char *channel)
{
	int			index;

	if (channel[0] == 0)
		return (end);
	if (start != end)
	{
		*end = ',';
		end += 1;
	}
	if (channel[0] != '#' && channel[0] != '&')
	{
		*end = '#';
		end += 1;
	}
	index = 0;
	while (end - start < 510 && channel[index])
	{
		*end = channel[index];
		end += 1;
		index += 1;
	}
	return (end);
}

static void		exec_list_with_arg(t_client *this, char *channels)
{
	char		**split;
	int			index;
	char		buffer[512];
	char		*tmp;

	split = ft_strsplit(channels, ',');
	buffer[0] = 0;
	tmp = buffer;
	if (!split)
		return ;
	index = 0;
	while (split[index])
	{
		tmp = fill_buffer(buffer, tmp, split[index]);
		index += 1;
	}
	*tmp = 0;
	array_del(split);
	client_write_sock(this, "LIST ");
	client_write_sock(this, buffer);
	client_write_sock(this, "\r\n");
}

void			client_exec_list(t_client *this, char *cmd)
{
	char		**split;

	if (!this->connected)
		return ;
	split = ft_strsplit(cmd, ' ');
	if (!split)
		return ;
	if (split[0] && !split[1])
	{
		client_write_sock(this, "LIST\r\n");
	}
	else if (split[0] && split[1])
	{
		exec_list_with_arg(this, split[1]);
	}
}
