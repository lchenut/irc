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

#include "data.h"
#include "command.h"

static t_ctrl_mvmt_data	*ctrlmv_new(char *sequence, void (*fn)(t_command *))
{
	t_ctrl_mvmt_data	*data;

	data = ft_calloc(sizeof(t_ctrl_mvmt_data));
	data->buf = sequence;
	data->fn = fn;
	return (data);
}

t_vector			*data_ctrl_mvmt(void)
{
	static t_vector	*data = NULL;

	if (!data)
	{
		data = vector_new();
		vector_push_back(data, ctrlmv_new("\177", command_del_left));
		vector_push_back(data, ctrlmv_new("\033[3~", command_del_right));
		vector_push_back(data, ctrlmv_new("\033[D", command_move_left));
		vector_push_back(data, ctrlmv_new("\033[C", command_move_right));
	}
	return (data);
}
