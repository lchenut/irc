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

#include "prog.h"
#include "client.h"

void			prog_run(t_prog *this)
{
	t_client	*client;

	if (this->ac == 2 || this->ac == 3)
		client = client_new(this->av[1], this->av[2]);
	else
		client = client_new(NULL, NULL);
	client_loop(client);
	client_del(client);
}
