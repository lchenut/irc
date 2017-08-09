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

t_rpl_status		rpl_tokenizer_apply_rule02(t_rpl_tokenizer *this)
{
	char			c;
	t_rpl_type		type;

	if (this->index_input == 0 && this->input[this->index_input] == ':')
	{
		type = RPL_TYPE_SERVERNAME;
		this->index_input += 1;
		while (true)
		{
			c = this->input[this->index_input];
			if (c == ' ' || c == '\0')
			{
				rpl_tokenizer_delimit(this, type);
				return (RPL_STATUS_APPLIED);
			}
			if (c == '!')
			{
				rpl_tokenizer_delimit(this, RPL_TYPE_NICK);
				this->index_input += 1;
				type = RPL_TYPE_USER;
			}
			if (c == '@' && type == RPL_TYPE_USER)
			{
				rpl_tokenizer_delimit(this, type);
				this->index_input += 1;
				type = RPL_TYPE_HOST;
			}
			else
			{
				rpl_tokenizer_addone(this);
			}
		}
	}
	return (RPL_STATUS_NOT_APPLIED);
}
