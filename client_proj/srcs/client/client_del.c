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

void			client_del(t_client *this)
{
	if (!this)
		return ;
	if (this->address)
		free(this->address);
	if (this->port)
		free(this->port);
	if (this->password)
		free(this->password);
	if (this->sock != -1)
		close(this->sock);
	if (this->visual)
		visual_del(this->visual);
	if (this->quit_msg)
		ft_putendl(this->quit_msg);
	if (this->socket_buf)
		buffer_del(this->socket_buf);
	if (this->command)
		command_del(this->command);
	if (this->nick)
		free(this->nick);
	free(this);
}
