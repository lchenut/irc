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

void				cmd_tokenizer_del(t_cmd_tokenizer *this)
{
	if (!this)
		return ;
	if (this->input)
		free(this->input);
	if (this->to_push)
		free(this->to_push);
	if (this->content)
		cmd_del(this->content);
	free(this);
}
