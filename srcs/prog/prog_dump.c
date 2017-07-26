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

void			prog_dump(t_prog *this)
{
	if (!this->av[1])
	{
		ft_putstr("address: (null)\n");
		ft_putstr("port:    (null)\n");
	}
	else
	{
		ft_putstr("address: ");
		ft_putendl(this->av[1]);
		ft_putstr("port:    ");
		ft_putendl(this->av[2]);
	}
}
