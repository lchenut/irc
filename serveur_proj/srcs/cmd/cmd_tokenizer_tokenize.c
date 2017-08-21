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

#include "cmd.h"

t_cmd_tokenizer_fn	g_cmd_tokenizer_fn[] =
{
	cmd_tokenizer_apply_rule01,
	cmd_tokenizer_apply_rule02,
	cmd_tokenizer_apply_rule03,
	cmd_tokenizer_apply_rule04,
	cmd_tokenizer_apply_rule05,
	NULL
};

t_cmd			*cmd_tokenizer_tokenize(const char *input)
{
	t_cmd_tokenizer	*this;
	t_cmd_status	type;
	t_cmd			*ret;
	int				index;

	this = cmd_tokenizer_new(input);
	index = 0;
	while (g_cmd_tokenizer_fn[index])
	{
		type = g_cmd_tokenizer_fn[index](this);
		if (type == CMD_STATUS_APPLIED)
			index = 0;
		else if (type == CMD_STATUS_NOT_APPLIED)
			index += 1;
		else
			break ;
	}
	ret = this->content;
	this->content = NULL;
	cmd_tokenizer_del(this);
	return (ret);
}
