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

#include "visual.h"

static bool				find_fn(void *data, void *context)
{
	return (ft_strcmp(((t_visual_channel *)data)->name, context) == 0);
}

t_visual_channel		*visual_get_visual_channel(t_visual *this,
		const char *chan)
{
	return (vector_find(this->channels, find_fn, (void *)chan));
}
