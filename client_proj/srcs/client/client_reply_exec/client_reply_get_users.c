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
#include "client_reply_exec.h"

void			client_reply_get_users(t_client *this,
		t_rpl_cnt *content, const t_reply *reply)
{
	client_reply_pop_params(this, content);
	if (!ft_strcmp(content->command, "353") && vector_len(content->params) == 2)
	{
		client_reply_353(this, content);
	}
	else if (!ft_strcmp(content->command, "366"))
	{
		client_reply_366(this, content);
	}
	(void)reply;
}
