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
#include "array.h"

static void		mode_current_channel(t_client *this)
{
	if (this->visual->current == vector_get_first(this->visual->channels))
	{
		visual_dump_date(this->visual, " HOME ");
		visual_print_red(this->visual, "Cannot do mode on HOME channel", " HOME ");
		visual_print_newline(this->visual, " HOME ");
		return ;
	}
	client_write_sock(this, "MODE ");
	client_write_sock(this, this->visual->current->name);
	client_write_sock(this, "\r\n");
}

static void		mode_current_channel_with_option(t_client *this, char **split)
{
	int			index;

	if (this->visual->current == vector_get_first(this->visual->channels))
	{
		visual_dump_date(this->visual, " HOME ");
		visual_print_red(this->visual, "Cannot do mode on HOME channel", " HOME ");
		visual_print_newline(this->visual, " HOME ");
		return ;
	}
	client_write_sock(this, "MODE ");
	client_write_sock(this, this->visual->current->name);
	index = 1;
	while (split[index])
	{
		client_write_sock(this, " ");
		client_write_sock(this, split[index]);
		index += 1;
	}
	client_write_sock(this, "\r\n");
}

static void		mode_chan_opt(t_client *this, char **split)
{
	int			index;

	client_write_sock(this, "MODE");
	index = 1;
	while (split[index])
	{
		client_write_sock(this, " ");
		client_write_sock(this, split[index]);
		index += 1;
	}
	client_write_sock(this, "\r\n");
}

void			client_exec_mode(t_client *this, char *s)
{
	char		**split;

	if (!this->connected)
		return ;
	split = ft_strsplit(s, ' ');
	if (!split)
		return ;
	if (!split[1])
		mode_current_channel(this);
	else if (split[1][0] == '+' || split[1][0] == '-')
		mode_current_channel_with_option(this, split);
	else
		mode_chan_opt(this, split);
	array_del(split);
}
