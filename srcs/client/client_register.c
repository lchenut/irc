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
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>

bool			should_register(t_client *this)
{
	if (this->password && ft_strlen(this->password) > 505)
		return (false);
	if (this->nick && ft_strlen(this->nick) > 505)
		return (false);
	return (true);
}

void			client_register(t_client *this)
{
	if (!should_register(this))
		return ;
	client_exec_pass(this, NULL);
	client_exec_nick(this, NULL);
	client_exec_user(this, NULL);
}
