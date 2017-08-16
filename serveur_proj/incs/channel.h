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

typedef struct		s_mode
{
	bool			private;
	bool			secret;
	bool			oninv;
	bool			topiclock;
	bool			msgrestricted;
	bool			moderate;
}					t_mode;

typedef struct		s_channel
{
	char			*name;
	char			*key;
	char			*topic;
	size_t			limit;
	t_mode			mode;
	t_vector		*users;
}					t_channel;

t_channel			*channel_new(char *name, char *key);
void				channel_del(t_channel *this);

void				channel_new_user(t_channel *this,
		t_user *user, t_server *server);

bool				channel_is_user_joined(t_channel *this, t_user *user);

#endif
