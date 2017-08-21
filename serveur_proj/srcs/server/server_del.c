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

#include "server.h"

static void		cmd_lst_del(void *data)
{
	free(((t_cmd_lst *)data)->line);
	free(data);
}

void			server_del(t_server *this)
{
	if (!this)
		return ;
	if (this->users)
		vector_del(this->users, (void(*)(void *))user_del);
	if (this->channels)
		vector_del(this->channels, (void(*)(void *))channel_del);
	if (this->querries)
		lst_del(this->querries, (void(*)(void *))query_del);
	if (this->cmd_lst)
		lst_del(this->cmd_lst, (void(*)(void *))cmd_lst_del);
	free(this);
}
