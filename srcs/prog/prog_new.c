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

t_prog			*prog_new(int ac, char **av)
{
	t_prog		*this;

	this = ft_calloc(sizeof(t_prog));
	this->ac = ac;
	this->av = av;
	if (ac == 3 && ft_strisnum(av[2]))
	{
		this->address = ft_strdup(av[1]);
		this->port = (unsigned short)ft_atoi(av[2]);
	}
	return (this);
}