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

#include "user.h"

void			user_exec_user(t_user *this, t_cmd *cmd, t_server *server)
{
	if (this->connected)
	{
		err_alreadyregistred(this, server);
		return ;
	}
	if (vector_len(cmd->params) < 4)
	{
		err_needmoreparams(this, cmd, server);
		return ;
	}
	if (!utils_is_valid_nickname(vector_get_first(cmd->params)))
	{
		return ;
	}
	if (this->user)
	{
		free(this->user);
	}
	this->user = ft_strdup(vector_get_first(cmd->params));
	if (this->nick && this->user)
	{
		user_try_connect(this, server);
	}
}
