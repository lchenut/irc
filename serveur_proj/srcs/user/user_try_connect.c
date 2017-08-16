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

void			rpl_welcome(t_user *this, t_server *server)
{
	char		buf[512];
	char		*tmp;
	t_querry	*querry;

	querry = querry_new(this);
	buf[0] = 0;
	tmp = utils_concat(buf, ":");
	tmp = utils_concat(tmp, IRC_NAME);
	tmp = utils_concat(tmp, " 001 ");
	tmp = utils_concat(tmp, this->nick);
	tmp = utils_concat(tmp, " :Welcome to Internet Relay Network ");
	tmp = utils_concat(tmp, this->nick);
	tmp = utils_concat(tmp, "!\r\n");
	querry->cmd = ft_strdup(buf);
	lst_push_back(server->querries, querry);
}

void			rpl_yourhost(t_user *this, t_server *server)
{
	char		buf[512];
	char		*tmp;
	t_querry	*querry;

	querry = querry_new(this);
	buf[0] = 0;
	tmp = utils_concat(buf, ":");
	tmp = utils_concat(tmp, IRC_NAME);
	tmp = utils_concat(tmp, " 002 ");
	tmp = utils_concat(tmp, this->nick);
	tmp = utils_concat(tmp, " :Your host is ");
	tmp = utils_concat(tmp, IRC_NAME);
	tmp = utils_concat(tmp, ", running version 1.0.0\r\n");
	querry->cmd = ft_strdup(buf);
	lst_push_back(server->querries, querry);
}

void			rpl_created(t_user *this, t_server *server)
{
	char		buf[512];
	char		*tmp;
	t_querry	*querry;

	querry = querry_new(this);
	buf[0] = 0;
	tmp = utils_concat(buf, ":");
	tmp = utils_concat(tmp, IRC_NAME);
	tmp = utils_concat(tmp, " 003 ");
	tmp = utils_concat(tmp, this->nick);
	tmp = utils_concat(tmp, " :This server was created wed, 19 jul 2017\r\n");
	querry->cmd = ft_strdup(buf);
	lst_push_back(server->querries, querry);
}

void			rpl_myinfo(t_user *this, t_server *server)
{
	char		buf[512];
	char		*tmp;
	t_querry	*querry;

	querry = querry_new(this);
	buf[0] = 0;
	tmp = utils_concat(buf, ":");
	tmp = utils_concat(tmp, IRC_NAME);
	tmp = utils_concat(tmp, " 004 ");
	tmp = utils_concat(tmp, this->nick);
	tmp = utils_concat(tmp, " :Ici faut mettre les infos du serveur\r\n");
	querry->cmd = ft_strdup(buf);
	lst_push_back(server->querries, querry);
}

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
		rpl_welcome(this, server);
		rpl_yourhost(this, server);
		rpl_created(this, server);
		rpl_myinfo(this, server);
	}
}
