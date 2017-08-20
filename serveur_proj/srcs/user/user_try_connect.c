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
#include "server.h"

void			user_try_connect(t_user *this, t_server *server)
{
	if (this->connected)
		return ;
	if (server->password &&
			(!this->pass || ft_strcmp(this->pass, server->password)))
		err_passwdmismatch(this, server);
	else
		this->connected = true;
	if (this->connected)
	{
		this->timeout = 2;
		rpl_welcome(this, server);
		rpl_yourhost(this, server);
		rpl_created(this, server);
		rpl_myinfo(this, server);
	}
}
