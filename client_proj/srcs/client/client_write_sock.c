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

void			client_write_sock(t_client *this, char *to_print)
{
	static char	buffer[512];
	static int	index = 0;
	int			tp_index;

	tp_index = 0;
	while (!((index == 510) || (to_print[tp_index] == 0) ||
		(to_print[tp_index] == '\n' || (to_print[tp_index] == '\r' &&
			to_print[tp_index + 1] == '\n'))))
	{
		buffer[index] = to_print[tp_index];
		index += 1;
		tp_index += 1;
	}
	if (index == 510 || to_print[tp_index] == '\n' ||
			(to_print[tp_index] == '\r' && to_print[tp_index + 1] == '\n'))
	{
		buffer[index] = '\r';
		buffer[index + 1] = '\n';
		write(this->sock, buffer, index + 2);
		ft_bzero(buffer, sizeof(buffer));
		index = 0;
	}
}
