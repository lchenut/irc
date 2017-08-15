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

void				reply_del(t_rpl_cnt *this)
{
	if (!this)
		return ;
	if (this->servername)
		free(this->servername);
	if (this->nick)
		free(this->nick);
	if (this->user)
		free(this->user);
	if (this->host)
		free(this->host);
	if (this->command)
		free(this->command);
	if (this->params)
		vector_del(this->params, free);
	free(this);
}
