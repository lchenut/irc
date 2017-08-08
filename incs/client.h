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

#ifndef CLIENT_H
# define CLIENT_H

# define DFL_SERVER_PORT "6667"

# include "basics.h"
# include "buffer.h"
# include "command.h"
# include "visual.h"
# include <sys/types.h>
# include <sys/select.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netdb.h>

typedef struct		s_client
{
	bool			should_quit;
	char			*quit_msg;
	bool			connected;
	char			*address;
	char			*port;
	unsigned short	us_port;
	char			*password;
	int				sock;
	fd_set			active_set;
	t_buffer		*socket_buf;
	t_visual		*visual;
	t_command		*command;
}					t_client;

t_client			*client_new(void);
void				client_del(t_client *this);

void				client_set_address(t_client *this, char *address);
void				client_set_port(t_client *this, char *port);
void				client_set_password(t_client *this, char *password);

void				client_try_connect(t_client *this);
void				client_try_connect_ipv4(t_client *this, struct addrinfo *i);
void				client_try_connect_ipv6(t_client *this, struct addrinfo *i);
void				client_try_connect_log(t_client *this, int af_family);

void				client_disconnect(t_client *this);

void				client_init_select(t_client *this);

void				client_loop(t_client *this);

void				client_read_from_stdin(t_client *this);
void				client_read_from_socket(t_client *this, int fd);
void				client_print_and_refresh(t_client *this,
		void (*fn)(t_visual *, char *), char *s);

void                (*client_get_execute_fn(char *s))(t_client *, char *);
void				client_exec(t_client *this);
void				client_exec_connect(t_client *this, char *cmd);

#endif
