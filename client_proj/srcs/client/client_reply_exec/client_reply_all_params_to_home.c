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

#include "client_reply_exec.h"
#include "client.h"
#include "visual.h"

static void		iter_fn(void *data, void *ctx)
{
	if (**(char **)ctx)
	{
		*(char **)ctx = ft_strjoinfree(*(char **)ctx, " ", 'l');
	}
	*(char **)ctx = ft_strjoinfree(*(char **)ctx, data, 'l');
}

void			client_reply_print_all_params_to_home(t_client *this,
		t_rpl_cnt *content, const t_reply *reply)
{
	char		*to_print;

	if (ft_strcmp(content->command, "001") == 0)
	{
		this->serv_connect = true;
	}
	client_reply_pop_params(this, content);
	to_print = ft_strnew(0);
	vector_iter(content->params, iter_fn, &to_print);
	visual_dump_date(this->visual, " HOME ");
	visual_print_channel(this->visual, to_print, " HOME ");
	visual_print_newline(this->visual, " HOME ");
	visual_move_curspos(this->visual, command_get_curspos(this->command));
	free(to_print);
	(void)reply;
}
