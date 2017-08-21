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

#include "server.h"

static bool	find_fn(void *data, void *context)
{
	return (((t_cmd_lst *)data)->user == context);
}

static void	del_fn(void *data)
{
	free(((t_cmd_lst *)data)->line);
	free(data);
}

void		server_clear_user_cmd_lst(t_server *this, t_user *user)
{
	lst_clear_if(this->cmd_lst, del_fn, find_fn, user);
}
