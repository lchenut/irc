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

static t_argparser	*prog_argparser(void)
{
	t_argparser		*arg;

	arg = argparser_new("client");
	argparser_set_usage(arg, "[ Options... ] [ Server [ Port ] ]");
	argparser_add_argument(arg,
			argparser_argument_new('s', "server",
				"Automaticaly connect to server/network", 2));
	argparser_add_argument(arg,
			argparser_argument_new('p', "port",
				"Autoconnect port (default: 6667)", 2));
	argparser_add_argument(arg,
			argparser_argument_new('w', "password", "Autoconnect password", 2));
	argparser_add_argument(arg,
			argparser_argument_new('?', "help", "Show help option", 1));
	return (arg);
}

t_prog				*prog_new(int ac, char **av)
{
	t_prog			*this;

	this = ft_calloc(sizeof(t_prog));
	this->ac = ac;
	this->av = av;
	this->arg = prog_argparser();
	this->res = argparser_parse_from_arr(this->arg, this->av);
	this->should_exit = false;
	return (this);
}
