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

static bool			is_last(t_cmd_tokenizer *this)
{
	return (this->input[this->index_input] == '\0' ||
			this->input[this->index_input] == '\n' ||
			(this->input[this->index_input] == '\r' &&
				this->input[this->index_input + 1] == '\n'));
}

t_cmd_status		cmd_tokenizer_apply_rule01(t_cmd_tokenizer *this)
{
	if (is_last(this))
	{
		if (this->index_to_push > 0)
		{
			if (!this->content->command)
				cmd_tokenizer_delimit(this, CMD_TYPE_COMMAND);
			else
				cmd_tokenizer_delimit(this, CMD_TYPE_PARAM);
		}
		return (CMD_STATUS_END_OF_INPUT);
	}
	return (CMD_STATUS_NOT_APPLIED);
}
