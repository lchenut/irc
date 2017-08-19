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

/*
** TODO: Apparemment, il faut gerer les 'autres cas', a voir
*/

static void		client_exec_pass_register(t_client *this)
{
	char		*buffer;
	char		*tmp;
	size_t		index;

	buffer = malloc(ft_strlen(this->password) + 10);
	index = 0;
	while ("PASS :"[index])
	{
		buffer[index] = "PASS :"[index];
		index += 1;
	}
	tmp = this->password;
	while (*tmp)
	{
		buffer[index] = *tmp;
		index += 1;
		tmp += 1;
	}
	buffer[index] = 0;
	client_write_sock(this, buffer);
	client_write_sock(this, "\r\n");
	free(buffer);
}

void			client_exec_pass(t_client *this, char *s)
{
	if (!s && !this->password)
		return ;
	if (!s)
	{
		client_exec_pass_register(this);
		return ;
	}
}
