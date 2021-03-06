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

static bool			is_last_colon(t_rpl_tokenizer *this)
{
	return (this->input[this->index_input] == '\0' ||
			this->input[this->index_input] == '\n' ||
			(this->input[this->index_input] == '\r' &&
				this->input[this->index_input + 1] == '\n'));
}

static bool			is_last(t_rpl_tokenizer *this)
{
	char			c1;
	char			c2;

	c1 = this->input[this->index_input];
	if (c1 == '\0')
		return (true);
	c2 = this->input[this->index_input + 1];
	return (c1 == ' ' || c1 == '\n' || (c1 == '\r' && c2 == '\n'));
}

t_rpl_status		rpl_tokenizer_apply_rule04(t_rpl_tokenizer *this)
{
	if (this->input[this->index_input] != ' ' && this->content->command)
	{
		if (this->input[this->index_input] == ':')
		{
			this->index_input += 1;
			while (!is_last_colon(this))
			{
				rpl_tokenizer_addone(this);
			}
		}
		while (!is_last(this))
		{
			rpl_tokenizer_addone(this);
		}
		rpl_tokenizer_delimit(this, RPL_TYPE_PARAM);
		return (RPL_STATUS_APPLIED);
	}
	return (RPL_STATUS_NOT_APPLIED);
}
