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


void			client_print_and_refresh(t_client *this,
		void (*fn)(t_visual *, char *), char *s)
{
	if (fn != NULL)
		fn(this->visual, s);
	if (this->command)
	{
		visual_print_prompt(this->visual,
			command_get_line_scaled(this->command));
		visual_move_curspos(this->visual, command_get_curspos(this->command));
	}
}
