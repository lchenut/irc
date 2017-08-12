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

#include "client_reply_exec.h"
#include "client.h"

void			client_reply_pop_params(t_client *this, t_rpl_cnt *content)
{
	if (ft_strcmp(vector_get_first(content->params), this->nick) == 0)
	{
		free(vector_pop_front(content->params));
		if (ft_strcmp(vector_get_first(content->params), "=") == 0)
		{
			free(vector_pop_front(content->params));
		}
	}
}
