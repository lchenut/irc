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

#include "cmd.h"

static void			iter_fn(void *data, int index)
{
	printf("param[%i]: %s\n", index, data);
}

void				cmd_dump(t_cmd *this)
{
	printf("======================\n");
	if (this->servername)
	{
		printf("servername: %s\n", this->servername);
	}
	else
	{
		printf("nick: %s\n", this->nick);
		printf("user: %s\n", this->user);
		printf("host: %s\n", this->host);
	}
	printf("command: %s\n", this->command);
	vector_iteri0(this->params, iter_fn);
	printf("======================\n");
}
