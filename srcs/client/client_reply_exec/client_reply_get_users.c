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

static void		iter_fn(void *data, void *ctx1, void *ctx2)
{
	visual_dump_date(ctx2, ctx1);
	visual_print_bold(ctx2, data, ctx1);
	visual_print_newline(ctx2, ctx1);
}

static int		sort_fn(const void *s1, const void *s2)
{
	return (ft_strcmp(s1, s2));
}

void			client_reply_get_users(t_client *this,
		t_rpl_cnt *content, const t_reply *reply)
{
	t_visual_channel	*channel;
	char				**users;
	char				*to_print;
	int					i;

	if (!ft_strcmp(content->command, "353") && vector_len(content->params) == 2)
	{
		channel = visual_get_visual_channel(this->visual,
				vector_get_first(content->params));
		if (channel == NULL)
		{
			return ;
		}
		users = ft_split(vector_get_last(content->params));
		i = 0;
		while (users[i])
		{
			vector_push_back(channel->users, users[i]);
			i += 1;
		}
		free(users);
	}
	else if (!ft_strcmp(content->command, "366"))
	{
		char	*chan;

		chan = vector_get_first(content->params);
		channel = visual_get_visual_channel(this->visual, chan);
		if (channel == NULL)
		{
			return ;
		}
		visual_dump_date(this->visual, chan);
		visual_print_green(this->visual, "Users: ", chan);
		visual_print_green(this->visual, chan, chan);
		visual_print_newline(this->visual, chan);
		vector_sortq(channel->users, sort_fn);
		to_print = ft_strnew(0);
		vector_iter2(channel->users, iter_fn, chan, this->visual);
	}
	(void)reply;
}
