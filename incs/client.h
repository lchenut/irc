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

# include "basics.h"
# include "buffer.h"
# include "visual.h"
# include <sys/types.h>
# include <sys/select.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netdb.h>

typedef struct		s_client
{
	bool			connected;
	char			*address;
	char			*port;
	unsigned short	us_port;
	int				sock;
	fd_set			active_set;
	t_buffer		*socket_buf;
}					t_client;

t_client			*client_new(char *address, char *port);
void				client_del(t_client *this);

void				client_try_connect(t_client *this);
void				client_try_connect_ipv4(t_client *this, struct addrinfo *i);
void				client_try_connect_ipv6(t_client *this, struct addrinfo *i);

void				client_init_select(t_client *this);

void				client_loop(t_client *this);

void				client_read_from_stdin(t_client *this);
void				client_read_from_socket(t_client *this, int fd);

#endif
