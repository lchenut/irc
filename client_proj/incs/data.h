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

#ifndef DATA_H
# define DATA_H

# include "vector.h"
# include "client.h"

typedef struct s_command	t_command;

typedef struct				s_ctrl_mvmt_data
{
	char					*buf;
	void					(*fn)(t_command *);
}							t_ctrl_mvmt_data;

typedef struct				s_command_data
{
	char					*low;
	char					*upp;
	void					(*exec_fn)(t_client *, char *cmd);
}							t_command_data;

t_vector					*data_ctrl_mvmt(bool clear);
t_vector					*data_command(bool clear);

#endif
