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
#include "server.h"
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

static void		not_valid_port_value(t_prog *this, char *value)
{
	ft_putstr_fd("server: ", 2);
	ft_putstr_fd(value, 2);
	ft_putendl_fd(" is not a valid port value", 2);
	argparser_print_help(this->arg);
	this->should_exit = true;
}

static void		set_port(t_prog *this, t_server *serv)
{
	char		*rem;
	char		*opt;

	rem = lst_first(this->res->remainders);
	opt = NULL;
	if (argparser_result_opt_is_set(this->res, "p"))
		opt = argparser_result_opt_get_arg(this->res, "p");
	if (!rem && !opt)
		serv->port = 6667;
	else if (!opt && (!ft_strisnum(rem) || ft_atoi(rem) <= 0))
		not_valid_port_value(this, rem);
	else if (!opt)
		serv->port = ft_atoi(rem);
	else if (!ft_strisnum(opt) || ft_atoi(opt) <= 0)
		not_valid_port_value(this, opt);
	else
		serv->port = ft_atoi(opt);
}

static void		set_password(t_prog *this, t_server *serv)
{
	if (argparser_result_opt_is_set(this->res, "w"))
		serv->password =
			ft_strdup(argparser_result_opt_get_arg(this->res, "w"));
	else
		serv->password = NULL;
}

void			prog_run(t_prog *this)
{
	t_server	*serv;

	manage_error(this);
	if (this->should_exit)
	{
		return ;
	}
	serv = server_new();
	set_port(this, serv);
	set_password(this, serv);
	server_create(serv);
	if (serv->err_msg)
	{
		ft_perror(serv->err_msg);
		return ;
	}
	server_loop(serv);
}
