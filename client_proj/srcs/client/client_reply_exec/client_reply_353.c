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

void			client_reply_353(t_client *this, t_rpl_cnt *content)
{
	t_visual_channel	*channel;
	char				**users;
	int					i;

	channel = visual_get_visual_channel(this->visual,
			vector_get_first(content->params));
	if (channel == NULL)
		return ;
	users = ft_split(vector_get_last(content->params));
	i = 0;
	while (users[i])
	{
		vector_push_back(channel->users, users[i]);
		i += 1;
	}
	free(users);
}
