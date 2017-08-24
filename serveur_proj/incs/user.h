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
# include "rpl.h"

# include <sys/select.h>
# include <netinet/in.h>

typedef struct s_server	t_server;
typedef struct sockaddr_in6	t_sai6;

typedef struct	s_user
{
	char		*nick;
	char		*user;
	char		*pass;
	int			timeout;
	int			msg_nb;
	int			socket;
	bool		connected;
	bool		flush_sock;
	t_buffer	*buffer;
	t_sai6		sin;
}				t_user;

t_user			*user_new(int socket, struct sockaddr_in6 *sin);
void			user_del(t_user *this);

void			user_fd_set(t_user *this, fd_set *set);

void			user_exec_command(t_user *this,
		char *line, t_server *serv);

typedef void	(*t_cmd_fn)(t_user *, t_cmd *, t_server *);

typedef struct	s_exec_cmd
{
	char		*cmd;
	t_cmd_fn	fn;
}				t_exec_cmd;

void			user_try_connect(t_user *this, t_server *server);

void			user_exec_nick(t_user *this, t_cmd *cmd, t_server *server);
void			user_exec_user(t_user *this, t_cmd *cmd, t_server *server);
void			user_exec_pass(t_user *this, t_cmd *cmd, t_server *server);
void			user_exec_join(t_user *this, t_cmd *cmd, t_server *server);
void			user_exec_topic(t_user *this, t_cmd *cmd, t_server *server);
void			user_exec_privmsg(t_user *this, t_cmd *cmd, t_server *server);
void			user_exec_list(t_user *this, t_cmd *cmd, t_server *server);
void			user_exec_names(t_user *this, t_cmd *cmd, t_server *server);
void			user_exec_pong(t_user *this, t_cmd *cmd, t_server *server);
void			user_exec_part(t_user *this, t_cmd *cmd, t_server *server);
void			user_exec_quit(t_user *this, t_cmd *cmd, t_server *server);
void			user_exec_mode(t_user *this, t_cmd *cmd, t_server *server);
void			user_exec_invite(t_user *this, t_cmd *cmd, t_server *server);

void			user_exec_chanmode(t_user *this, t_cmd *cmd,
		t_server *server, t_channel *channel);
void			user_exec_chanmode_minus(t_user *this, t_cmd *cmd,
		t_server *server, t_channel *channel);
void			user_exec_chanmode_plus(t_user *this, t_cmd *cmd,
		t_server *server, t_channel *channel);

void			err_useronchannel(t_user *t, char *n, char *c, t_server *s);
void			err_norecipient(t_user *this, char *cmd, t_server *server);
void			err_notextsend(t_user *this, t_server *server);
void			err_toomanytargets(t_user *this, char *dest, t_server *server);
void			err_cannotsendtochan(t_user *this, char *s, t_server *server);
void			err_keyset(t_user *this, char *chan, t_server *server);
void			err_unknownmode(t_user *this, char mode, t_server *server);
void			err_chanoprivsneeded(t_user *this, char *c, t_server *server);
void			err_nosuchchannel(t_user *this, char *chan, t_server *server);
void			err_nosuchnick(t_user *this, char *nick, t_server *server);
void			err_notonchannel(t_user *this, char *chan, t_server *server);
void			err_channelisfull(t_user *this, char *chan, t_server *server);
void			err_inviteonlychan(t_user *this, char *chan, t_server *server);
void			err_badchannelkey(t_user *this, char *chan, t_server *server);
void			err_nonicknamegiven(t_user *this, t_server *server);
void			err_nickcollision(t_user *this, char *nick, t_server *server);
void			err_nicknameinuse(t_user *this, char *nick, t_server *server);
void			err_erroneusnickname(t_user *this, char *nick, t_server *serve);
void			err_alreadyregistred(t_user *this, t_server *server);
void			err_needmoreparams(t_user *this, t_cmd *cmd, t_server *server);
void			err_passwdmismatch(t_user *this, t_server *server);

#endif
