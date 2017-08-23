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

#ifndef CHANNEL_H
# define CHANNEL_H

# include "basics.h"
# include "user.h"
# include "utils.h"

typedef struct s_server	t_server;

typedef struct	s_mode
{
	bool		private;
	bool		secret;
	bool		oninv;
	bool		topiclock;
	bool		msgrestrict;
	bool		moderate;
}				t_mode;

typedef struct	s_channel
{
	char		*name;
	char		*key;
	char		*topic;
	size_t		limit;
	t_mode		mode;
	t_vector	*users;
	t_vector	*chanop;
	t_vector	*moderate;
}				t_channel;

t_channel		*channel_new(char *name, char *key);
void			channel_del(t_channel *this);

void			channel_new_user(t_channel *this,
		t_user *user, t_server *server);
void			channel_del_user(t_channel *this, t_user *user);
void			channel_new_chanop(t_channel *this, t_user *user,
		char *to_chanop, t_server *server);
void			channel_del_chanop(t_channel *this, t_user *user);
void			channel_new_moderate(t_channel *this, t_user *user,
		char *to_moderate, t_server *server);
void			channel_del_moderate(t_channel *this, char *username);
void			channel_user_part(t_channel *this, t_user *user,
		t_server *server);

bool			channel_is_user_joined(t_channel *this, t_user *user);
bool			channel_is_user_chanop(t_channel *this, t_user *user);
bool			channel_is_user_moderate(t_channel *this, t_user *user);

void			channel_send_msg_from(t_channel *this, t_user *user,
		char *msg, t_server *server);

void			channel_set_private(t_channel *this);
void			channel_set_secret(t_channel *this);
void			channel_set_oninv(t_channel *this);
void			channel_set_topiclock(t_channel *this);
void			channel_set_msgrestrict(t_channel *this);
void			channel_set_moderate(t_channel *this);

void			channel_set_limit(t_channel *this, char *limit);
void			channel_set_key(t_channel *this,
		t_user *user, char *key, t_server *server);

void			channel_unset_private(t_channel *this);
void			channel_unset_secret(t_channel *this);
void			channel_unset_oninv(t_channel *this);
void			channel_unset_topiclock(t_channel *this);
void			channel_unset_msgrestrict(t_channel *this);
void			channel_unset_moderate(t_channel *this);

void			channel_unset_key(t_channel *this);

#endif
