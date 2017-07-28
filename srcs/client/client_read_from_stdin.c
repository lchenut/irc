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

void			client_read_from_stdin(t_client *this)
{
	char		c;
	
	c = visual_get_char(this->visual);
	if (c == '\n')
		; // TODO: SA PETE
	else
	{
		command_push(this->command, c);
		visual_print_prompt(this->visual, command_get_line(this->command));
		visual_move_curspos(this->visual, command_get_curspos(this->command));
	}
	if (ft_isprint(c))
		LOG_DEBUG("%#hhx (%c)", c, c)
	else
		LOG_DEBUG("%#hhx", c)
}
