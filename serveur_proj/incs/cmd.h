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

#ifndef CMD_H
# define CMD_H

# include "basics.h"
# include "utils.h"

typedef enum			e_cmd_type
{
	CMD_TYPE_SERVERNAME,
	CMD_TYPE_NICK,
	CMD_TYPE_USER,
	CMD_TYPE_HOST,
	CMD_TYPE_COMMAND,
	CMD_TYPE_PARAM
}						t_cmd_type;

typedef struct			s_cmd
{
	char				*servername;
	char				*nick;
	char				*user;
	char				*host;
	char				*command;
	t_vector			*params;
}						t_cmd;

typedef enum			e_cmd_status
{
	CMD_STATUS_APPLIED,
	CMD_STATUS_NOT_APPLIED,
	CMD_STATUS_END_OF_INPUT
}						t_cmd_status;

typedef struct			s_cmd_tokenizer
{
	t_cmd				*content;
	char				*input;
	size_t				index_input;
	char				*to_push;
	size_t				index_to_push;
}						t_cmd_tokenizer;

t_cmd_tokenizer			*cmd_tokenizer_new(const char *input);
void					cmd_tokenizer_del(t_cmd_tokenizer *this);

t_cmd_status			cmd_tokenizer_apply_rule01(t_cmd_tokenizer *this);
t_cmd_status			cmd_tokenizer_apply_rule02(t_cmd_tokenizer *this);
t_cmd_status			cmd_tokenizer_apply_rule03(t_cmd_tokenizer *this);
t_cmd_status			cmd_tokenizer_apply_rule04(t_cmd_tokenizer *this);
t_cmd_status			cmd_tokenizer_apply_rule05(t_cmd_tokenizer *this);
t_cmd					*cmd_tokenizer_tokenize(const char *input);

void					cmd_tokenizer_delimit(t_cmd_tokenizer *this,
		t_cmd_type type);
void					cmd_tokenizer_addone(t_cmd_tokenizer *this);

typedef t_cmd_status	(*t_cmd_tokenizer_fn)(t_cmd_tokenizer *);

t_cmd					*cmd_new(void);
void					cmd_del(t_cmd *this);
void					cmd_dump(t_cmd *this);

#endif
