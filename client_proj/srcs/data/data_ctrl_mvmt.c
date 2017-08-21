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

t_vector				*data_ctrl_mvmt(void)
{
	static t_vector	*data = NULL;

	if (!data)
	{
		data = vector_new();
		vector_push_back(data, ctrlmv_new("\033[A", command_history_up));
		vector_push_back(data, ctrlmv_new("\033[B", command_history_down));
		vector_push_back(data, ctrlmv_new("\033[C", command_move_right));
		vector_push_back(data, ctrlmv_new("\033[D", command_move_left));
		vector_push_back(data, ctrlmv_new("\177", command_del_left));
		vector_push_back(data, ctrlmv_new("\033[3~", command_del_right));
		vector_push_back(data, ctrlmv_new("\001", command_move_home));
		vector_push_back(data, ctrlmv_new("\004", command_ctrl_d));
		vector_push_back(data, ctrlmv_new("\005", command_move_end));
		vector_push_back(data, ctrlmv_new("\011", command_tabulation));
		vector_push_back(data, ctrlmv_new("\033[Z", command_shift_tabulation));
	}
	return (data);
}
