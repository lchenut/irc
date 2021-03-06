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

static char		*set_channel(char *buffer, char *tmp, char *chan)
{
	if (!chan)
		return (tmp);
	while (tmp - buffer < 510 && *chan)
	{
		if ((tmp[-1] == ',' || tmp[-1] == ' ') &&
				*chan != ',' && *chan != '#' && *chan != '&')
		{
			*tmp = '#';
			tmp += 1;
		}
		if ((tmp[-1] == ',' || tmp[-1] == ' ') && *chan == ',')
			;
		else
		{
			*tmp = *chan;
			tmp += 1;
			chan += 1;
		}
	}
	return (tmp);
}

static char		*set_key(char *buffer, char *tmp, char *key)
{
	if (!key)
		return (tmp);
	*tmp = ' ';
	tmp += 1;
	while (tmp - buffer < 510 && *key)
	{
		*tmp = *key;
		tmp += 1;
		key += 1;
	}
	return (tmp);
}

void			client_exec_join(t_client *this, char *s)
{
	char		**split;
	char		buffer[512];
	char		*tmp;

	if (!this->connected)
		return ;
	split = ft_strsplit(s, ' ');
	if (!split)
		return ;
	if (!split[0] || !split[1])
	{
		array_del(split);
		return ;
	}
	tmp = utils_concat(buffer, "JOIN ");
	tmp = set_channel(buffer, tmp, split[1]);
	if (split[2])
		tmp = set_key(buffer, tmp, split[2]);
	*tmp = 0;
	client_write_sock(this, buffer);
	client_write_sock(this, "\r\n");
	array_del(split);
}
