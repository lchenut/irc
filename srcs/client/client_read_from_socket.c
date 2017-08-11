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
	while (g_replies[index].command)
	{
		if (ft_strcmp(g_replies[index].command, content->command) == 0)
			break ;
		index += 1;
	}
	reply_dump(content);
	rep = g_replies + index;
	if (!rep->command)
	{
		LOG_WARN("Command unknown");
	}
	else
		rep->fn(this, content, rep);
	(void)this;
}

void			client_read_from_socket(t_client *this, int fd)
{
	char		*rep;
	t_rpl_cnt	*content;

	if (!this->socket_buf)
		this->socket_buf = buffer_new(fd);
	if (!buffer_read_from_fd(this->socket_buf, fd))
	{
		client_disconnect(this);
		return ;
	}
	while ((rep = buffer_pop_line(this->socket_buf)))
	{
		if (rep && !ft_strchr(rep, '\n'))
			buffer_flush_fd(this->socket_buf, fd);
		else
		{
			content = rpl_tokenizer_tokenize(rep);
			client_read(this, content);
		}
		free(rep);
	}
}
