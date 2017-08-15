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

#include "client.h"
#include "replies.h"

void			client_reply_exec_default(t_client *this, t_rpl_cnt *content,
		const t_reply *reply)
{
	char		*to_print;

	to_print = reply_to_string(content);
	visual_dump_date(this->visual, "HOME");
	visual_print_channel(this->visual, to_print, "HOME");
	visual_print_newline(this->visual, "HOME");
	visual_move_curspos(this->visual, command_get_curspos(this->command));
	free(to_print);
	(void)reply;
}
