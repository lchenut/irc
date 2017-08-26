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

void				client_read(t_client *this, t_rpl_cnt *content)
{
	int				index;
	const t_reply	*rep;

	index = 0;
	if (!content->command)
	{
		return ;
	}
	while (g_replies[index].command)
	{
		if (ft_strcmp(g_replies[index].command, content->command) == 0)
			break ;
		index += 1;
	}
	rep = g_replies + index;
	if (rep->command)
	{
		rep->fn(this, content, rep);
	}
}

static void			client_pop_line(t_client *this)
{
	char			*rep;
	t_rpl_cnt		*content;

	while ((rep = buffer_pop_line(this->socket_buf)))
	{
		if (rep && !ft_strchr(rep, '\n'))
			this->flush_sock = true;
		else
		{
			content = rpl_tokenizer_tokenize(rep);
			client_read(this, content);
			reply_del(content);
		}
		free(rep);
	}
}

void				client_read_from_socket(t_client *this, int fd)
{
	int				flush_ret;

	if (this->flush_sock == true)
	{
		flush_ret = buffer_flush_fd(this->socket_buf, fd);
		if (flush_ret <= 0)
		{
			client_disconnect(this);
			return ;
		}
		else if (flush_ret == 1)
			this->flush_sock = false;
		else
			return ;
	}
	if (!buffer_read_from_fd(this->socket_buf, fd))
	{
		client_disconnect(this);
		return ;
	}
	client_pop_line(this);
}
