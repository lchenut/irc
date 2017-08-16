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

void			err_nosuchchannel(t_user *this, char *name, t_server *server)
{
	char		buf[512];
	char		*tmp;
	char		*base;
	t_querry	*querry;

	querry = querry_new(this);
	buf[0] = 0;
	tmp = utils_concat(buf, ":");
	tmp = utils_concat(tmp, IRC_NAME);
	tmp = utils_concat(tmp, " 403 ");
	base = name;
	while (*name && name - base <= 50)
	{
		*tmp = *name;
		name += 1;
		tmp += 1;
	}
	tmp = utils_concat(tmp, " :No such channel\r\n");
	querry->cmd = ft_strdup(buf);
	lst_push_back(server->querries, querry);
}
