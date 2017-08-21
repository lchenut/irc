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

#ifndef CLIENT_REPLY_EXEC_H
# define CLIENT_REPLY_EXEC_H

# include "replies.h"

typedef struct s_client	t_client;

void	client_reply_pop_params(t_client *this, t_rpl_cnt *content);

void	client_reply_exec_default(t_client *t, t_rpl_cnt *c, const t_reply *r);

void	client_reply_print_all_params_to_home(t_client *t,
		t_rpl_cnt *c, const t_reply *r);

void	client_reply_ping(t_client *t, t_rpl_cnt *c, const t_reply *r);
void	client_reply_join(t_client *t, t_rpl_cnt *c, const t_reply *r);
void	client_reply_part(t_client *t, t_rpl_cnt *c, const t_reply *r);
void	client_reply_privmsg(t_client *t, t_rpl_cnt *c, const t_reply *r);
void	client_reply_quit(t_client *t, t_rpl_cnt *c, const t_reply *r);
/*
** 331 / 332
*/
void	client_reply_topic(t_client *t, t_rpl_cnt *c, const t_reply *r); // 331 / 332
/*
** 353 / 366
*/
void	client_reply_get_users(t_client *t, t_rpl_cnt *c, const t_reply *r);
void	client_reply_353(t_client *t, t_rpl_cnt *c);
void	client_reply_366(t_client *t, t_rpl_cnt *c);

void	client_reply_401(t_client *t, t_rpl_cnt *c, const t_reply *r);

#endif
