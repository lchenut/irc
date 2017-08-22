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

#include "replies.h"

t_rpl_tokenizer_fn	g_rpl_tokenizer_fn[] =
{
	rpl_tokenizer_apply_rule01,
	rpl_tokenizer_apply_rule02,
	rpl_tokenizer_apply_rule03,
	rpl_tokenizer_apply_rule04,
	rpl_tokenizer_apply_rule05,
	NULL
};

t_rpl_cnt			*rpl_tokenizer_tokenize(const char *input)
{
	t_rpl_tokenizer	*this;
	t_rpl_status	type;
	t_rpl_cnt		*ret;
	int				index;

	this = rpl_tokenizer_new(input);
	index = 0;
	while (g_rpl_tokenizer_fn[index])
	{
		type = g_rpl_tokenizer_fn[index](this);
		if (type == RPL_STATUS_APPLIED)
			index = 0;
		else if (type == RPL_STATUS_NOT_APPLIED)
			index += 1;
		else
			break ;
	}
	ret = this->content;
	this->content = NULL;
	rpl_tokenizer_del(this);
	return (ret);
}
