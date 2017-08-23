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

void			client_exec_connect(t_client *this, char *cmd)
{
	char		**split;

	if (this->connected)
		client_disconnect(this);
	split = ft_strsplit(cmd, ' ');
	if (split[1])
		client_set_address(this, split[1]);
	if (split[1] && split[2])
		client_set_port(this, split[2]);
	array_del(split);
	client_try_connect(this);
	if (this->connected)
	{
		client_register(this);
	}
}
