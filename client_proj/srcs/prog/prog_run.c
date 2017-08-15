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
#include "argparser/argparser.h"

static void		manage_error(t_prog *this)
{
	if (this->res->err_msg)
	{
		argparser_result_print_error_with_help(this->res);
		this->should_exit = true;
	}
	else if (argparser_result_opt_is_set(this->res, "?"))
	{
		argparser_print_help(this->arg);
		this->should_exit = true;
	}
}

static void		manage_client(t_prog *this, t_client *client)
{
	if (lst_first(this->res->remainders))
		client_set_address(client, lst_first(this->res->remainders));
	if (lst_get(this->res->remainders, 1))
		client_set_port(client, lst_get(this->res->remainders, 1));
	if (argparser_result_opt_is_set(this->res, "s"))
		client_set_address(client,
				argparser_result_opt_get_arg(this->res, "s"));
	if (argparser_result_opt_is_set(this->res, "p"))
		client_set_port(client, argparser_result_opt_get_arg(this->res, "p"));
	if (argparser_result_opt_is_set(this->res, "w"))
		client_set_password(client,
				argparser_result_opt_get_arg(this->res, "w"));
	if (argparser_result_opt_is_set(this->res, "n"))
		client_set_nick(client,
				argparser_result_opt_get_arg(this->res, "n"));
}

void			prog_run(t_prog *this)
{
	t_client	*client;

	manage_error(this);
	if (this->should_exit)
	{
		return ;
	}
	client = client_singleton();
	manage_client(this, client);
	client_try_connect(client);
	if (client->connected)
	{
		client_register(client);
	}
	client_loop(client);
	client_del(client);
}
