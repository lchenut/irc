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

#ifndef USER_H
# define USER_H

# include "basics.h"
# include "buffer.h"
# include "utils.h"
# include "cmd.h"

# include <sys/select.h>
# include <netinet/in.h>

typedef struct s_server	t_server;

typedef struct			s_user
{
	char				*nick;
	char				*user;
	char				*pass;
	int					timeout;
	int					socket;
	bool				connected;
	t_buffer			*buffer;
	struct sockaddr_in6	sin;
}						t_user;

t_user					*user_new(int socket, struct sockaddr_in6 *sin);
void					user_del(t_user *this);

void					user_fd_set(t_user *this, fd_set *set);

void					user_exec_command(t_user *this,
		char *line, t_server *serv);

typedef void			(*t_cmd_fn)(t_user *, t_cmd *, t_server *);

typedef struct  s_exec_cmd
{
	char        *cmd;
	t_cmd_fn    fn;
}               t_exec_cmd;

void			user_try_connect(t_user *this, t_server *server);

void            user_exec_nick(t_user *this, t_cmd *cmd, t_server *server);
void            user_exec_user(t_user *this, t_cmd *cmd, t_server *server);
void            user_exec_pass(t_user *this, t_cmd *cmd, t_server *server);

void			rpl_welcome(t_user *this, t_server *server);
void			rpl_yourhost(t_user *this, t_server *server);
void			rpl_created(t_user *this, t_server *server);
void			rpl_myinfo(t_user *this, t_server *server);

void            err_nonicknamegiven(t_user *this, t_server *server);
void            err_nickcollision(t_user *this, char *nick, t_server *server);
void            err_nicknameinuse(t_user *this, char *nick, t_server *server);
void            err_erroneusnickname(t_user *this, char *nick, t_server *serve);
void            err_alreadyregistred(t_user *this, t_server *server);
void            err_needmoreparams(t_user *this, t_cmd *cmd, t_server *server);
void            err_passwdmismatch(t_user *this, t_server *server);

#endif
