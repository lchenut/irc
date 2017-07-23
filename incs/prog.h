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

#ifndef PROG_H
# define PROG_H

# include "basics.h"

typedef struct		s_prog
{
	int				ac;
	char			**av;
	char			*address;
	unsigned short	port;
}					t_prog;

t_prog				*prog_new(int ac, char **av);
void				prog_del(t_prog *this);

void				prog_run(t_prog *this);
void				prog_dump(t_prog *this);
void				prog_usage(t_prog *this);

#endif