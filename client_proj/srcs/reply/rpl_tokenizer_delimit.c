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

static char			*inner_delimit(t_rpl_tokenizer *this)
{
	char			*ret;

	ret = ft_strdup(this->to_push);
	ft_bzero(this->to_push, this->index_to_push);
	this->index_to_push = 0;
	return (ret);
}

void				rpl_tokenizer_delimit(t_rpl_tokenizer *this, t_rpl_type type)
{
	char			*to_push;

	to_push = inner_delimit(this);
	if (type == RPL_TYPE_SERVERNAME)
		this->content->servername = to_push;
	else if (type == RPL_TYPE_NICK)
		this->content->nick = to_push;
	else if (type == RPL_TYPE_USER)
		this->content->user = to_push;
	else if (type == RPL_TYPE_HOST)
		this->content->host = to_push;
	else if (type == RPL_TYPE_COMMAND)
		this->content->command = to_push;
	else if (type == RPL_TYPE_PARAM)
		vector_push_back(this->content->params, to_push);
}
