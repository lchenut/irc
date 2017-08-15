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

void			client_reply_part(t_client *this, t_rpl_cnt *content,
		const t_reply *reply)
{
	client_reply_pop_params(this, content);
	if (content->nick && !ft_strcmp(content->nick, this->nick) &&
			vector_get_first(content->params))
	{
		visual_channel_del_by_name(this->visual,
				vector_get_first(content->params));
	}
	else
	{
		// TODO: Trouver un moyen de tester le depart d'un autre pecnos sur un
		// serveur pour voir la reaction du serveur
		// et resoudre le probleme
	}
	(void)reply;
}
