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

t_rpl_tokenizer		*rpl_tokenizer_new(const char *input)
{
	t_rpl_tokenizer	*this;

	this = ft_calloc(sizeof(t_rpl_tokenizer));
	this->content = reply_new();
	this->input = ft_strdup(input);
	this->index_input = 0;
	this->to_push = ft_strnew(ft_strlen(input));
	this->index_to_push = 0;
	return (this);
}
