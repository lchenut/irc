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

#ifndef SERVER_H
# define SERVER_H

# define DFL_PORT 6667

# include "basics.h"
# include "user.h"
# include "channel.h"
# include "lst.h"
# include "utils.h"

# include <sys/types.h>
# include <sys/select.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netdb.h>

typedef struct		s_query
{
	t_user			*user;
	char			*cmd;
}					t_query;

t_query			*query_new(t_user *user);
void				query_del(t_query *this);

typedef struct		s_server
{
	int				port;
	int				socket;
	bool			connected;
	char			*err_msg;
	char			*password;
	size_t			maxchannels;
	fd_set			read_set;
	fd_set			write_set;
	t_vector		*users;
	t_vector		*channels;
	t_lst			*querries;
}					t_server;

t_server			*server_new(void);
void				server_del(t_server *this);

void				server_create(t_server *this);

void				server_loop(t_server *this);

t_user				*server_get_user_from_socket(t_server *this, int csocket);
t_user				*server_get_user_from_nick(t_server *this, char *nick);
void				server_delete_user_from_socket(t_server *this, int csocket);

t_channel			*server_create_or_get_channel(t_server *this,
		char *name, char *key);
t_channel			*server_get_channel_from_name(t_server *this, char *name);

#endif
