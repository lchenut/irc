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

#ifndef RPL_H
# define RPL_H

# include "basics.h"
# include "utils.h"

typedef struct s_user		t_user;
typedef struct s_server		t_server;
typedef struct s_channel	t_channel;

void			rpl_welcome(t_user *this, t_server *server);
void			rpl_yourhost(t_user *this, t_server *server);
void			rpl_created(t_user *this, t_server *server);
void			rpl_myinfo(t_user *this, t_server *server);

void			rpl_notopic(t_user *this, t_channel *channel, t_server *server);
void			rpl_topic(t_user *this, t_channel *channel, t_server *server);

#endif
