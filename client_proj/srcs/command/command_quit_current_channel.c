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

#include "command.h"
#include "client.h"

static void	exec_part_current_channel(t_client *this)
{
	char	*current;

	current = this->visual->current->name;
	if (*current == '#' || *current == '&')
	{
		client_write_sock(this, "PART ");
		client_write_sock(this, current);
		client_write_sock(this, "\r\n");
	}
	else if (ft_strcmp(current, " HOME "))
	{
		visual_channel_del_by_name(this->visual, current);
		visual_move_curspos(this->visual, command_get_curspos(this->command));
	}
}

void			command_ctrl_d(t_command *this)
{
	exec_part_current_channel(client_singleton());
	(void)this;
}
