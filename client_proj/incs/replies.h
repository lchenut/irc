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

#ifndef REPLIES_H
# define REPLIES_H

# include "basics.h"

typedef struct s_client	t_client;
typedef struct s_reply	t_reply;

typedef enum			e_rpl_type
{
	RPL_TYPE_SERVERNAME,
	RPL_TYPE_NICK,
	RPL_TYPE_USER,
	RPL_TYPE_HOST,
	RPL_TYPE_COMMAND,
	RPL_TYPE_PARAM
}						t_rpl_type;

typedef struct			s_rpl_cnt
{
	char				*servername;
	char				*nick;
	char				*user;
	char				*host;
	char				*command;
	t_vector			*params;
}						t_rpl_cnt;

typedef enum			e_rpl_status
{
	RPL_STATUS_APPLIED,
	RPL_STATUS_NOT_APPLIED,
	RPL_STATUS_END_OF_INPUT
}						t_rpl_status;

typedef struct			s_rpl_tokenizer
{
	t_rpl_cnt			*content;
	char				*input;
	size_t				index_input;
	char				*to_push;
	size_t				index_to_push;
}						t_rpl_tokenizer;

t_rpl_tokenizer			*rpl_tokenizer_new(const char *input);
void					rpl_tokenizer_del(t_rpl_tokenizer *this);

t_rpl_status			rpl_tokenizer_apply_rule01(t_rpl_tokenizer *this);
t_rpl_status			rpl_tokenizer_apply_rule02(t_rpl_tokenizer *this);
t_rpl_status			rpl_tokenizer_apply_rule03(t_rpl_tokenizer *this);
t_rpl_status			rpl_tokenizer_apply_rule04(t_rpl_tokenizer *this);
t_rpl_status			rpl_tokenizer_apply_rule05(t_rpl_tokenizer *this);
t_rpl_cnt				*rpl_tokenizer_tokenize(const char *input);

void					rpl_tokenizer_delimit(t_rpl_tokenizer *this,
		t_rpl_type type);
void					rpl_tokenizer_addone(t_rpl_tokenizer *this);

typedef t_rpl_status	(*t_rpl_tokenizer_fn)(t_rpl_tokenizer *);

typedef struct			s_reply
{
	bool				is_reply;
	char				*command;
	char				*message;
	int					args_number;
	void				(*fn)(t_client *, t_rpl_cnt *, const struct s_reply *);
}						t_reply;

extern const t_reply	g_replies[];

t_rpl_cnt				*reply_new(void);
void					reply_del(t_rpl_cnt *this);
void					reply_dump(t_rpl_cnt *this);
char					*reply_to_string(t_rpl_cnt *this);

#endif
