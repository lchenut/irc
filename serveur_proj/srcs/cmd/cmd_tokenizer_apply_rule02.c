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

static t_cmd_status	apply_rule02_end(t_cmd_tokenizer *this, t_cmd_type type)
{
	cmd_tokenizer_delimit(this, type);
	return (CMD_STATUS_APPLIED);
}

static void			apply_rule02_user(t_cmd_tokenizer *this, t_cmd_type *type)
{
	cmd_tokenizer_delimit(this, CMD_TYPE_NICK);
	this->index_input += 1;
	*type = CMD_TYPE_USER;
}

static void			apply_rule02_host(t_cmd_tokenizer *this, t_cmd_type *type)
{
	cmd_tokenizer_delimit(this, *type);
	this->index_input += 1;
	*type = CMD_TYPE_HOST;
}

t_cmd_status		cmd_tokenizer_apply_rule02(t_cmd_tokenizer *this)
{
	char			c;
	t_cmd_type		type;

	if (this->index_input == 0 && this->input[this->index_input] == ':')
	{
		type = CMD_TYPE_SERVERNAME;
		this->index_input += 1;
		while (true)
		{
			c = this->input[this->index_input];
			if (c == ' ' || c == '\0')
				return (apply_rule02_end(this, type));
			if (c == '!')
				apply_rule02_user(this, &type);
			if (c == '@' && type == CMD_TYPE_USER)
				apply_rule02_host(this, &type);
			else
				cmd_tokenizer_addone(this);
		}
	}
	return (CMD_STATUS_NOT_APPLIED);
}
