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

static void		inner_iter_fn(t_visual *visual, char *chan, char *s, size_t pad)
{
	char		*spad;

	visual_print_bold(visual, s, chan);
	spad = ft_strfnew(pad - ft_strlen(s) + 1, ' ');
	visual_print_channel(visual, spad, chan);
	free(spad);
}

static void		iter_fn_cur_0(t_visual *visual,
		t_visual_channel *channel, void *data)
{
	visual_dump_date(visual, channel->name);
	if (PROMPT_SIZE + channel->longest_users_name + 1 > (size_t)COLS)
	{
		visual_print_bold(visual, data, channel->name);
		visual_print_newline(visual, channel->name);
	}
	else
	{
		inner_iter_fn(visual, channel->name, data, channel->longest_users_name);
		channel->current_line += channel->longest_users_name + 1;
	}
}

static void		iter_fn(void *data, void *ctx1, void *ctx2)
{
	t_visual_channel	*channel;
	t_visual			*visual;

	channel = ctx1;
	visual = ctx2;
	if (channel->current_line == 0)
	{
		iter_fn_cur_0(visual, channel, data);
	}
	else
	{
		if (PROMPT_SIZE + channel->current_line +
				channel->longest_users_name + 1 > (size_t)COLS)
		{
			visual_print_newline(visual, channel->name);
			visual_dump_date(visual, channel->name);
			channel->current_line = 0;
		}
		inner_iter_fn(visual, channel->name, data, channel->longest_users_name);
		channel->current_line += channel->longest_users_name + 1;
	}
}

static void		find_longest_string_fn(void *data, void *context)
{
	size_t		len;

	len = ft_strlen(data);
	if (len > *(size_t *)context)
		*(size_t *)context = len;
}

void			client_reply_366(t_client *this, t_rpl_cnt *content)
{
	t_visual_channel	*channel;

	channel = visual_get_visual_channel(this->visual,
			vector_get_first(content->params));
	if (channel == NULL)
		return ;
	visual_dump_date(this->visual, channel->name);
	visual_print_green(this->visual, "Users: ", channel->name);
	visual_print_green(this->visual, channel->name, channel->name);
	visual_print_newline(this->visual, channel->name);
	vector_sortq(channel->users, (int(*)(const void *, const void *))ft_strcmp);
	vector_iter(channel->users, find_longest_string_fn,
			&(channel->longest_users_name));
	channel->current_line = 0;
	vector_iter2(channel->users, iter_fn, channel, this->visual);
	visual_print_newline(this->visual, channel->name);
}
