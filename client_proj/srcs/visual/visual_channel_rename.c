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

static int		sort_fn(const void *data1, const void *data2)
{
	if (!ft_strcmp(((t_visual_channel *)data1)->name, " HOME "))
		return (-1);
	if (!ft_strcmp(((t_visual_channel *)data2)->name, " HOME "))
		return (1);
	return (ft_strcmp(((t_visual_channel *)data1)->name,
				((t_visual_channel *)data2)->name));
}

void			visual_channel_rename(t_visual *this, char *old, char *new)
{
	t_visual_channel	*channel;

	channel = visual_get_visual_channel(this, old);
	if (channel == NULL)
	{
		return ;
	}
	free(channel->name);
	channel->name = ft_strdup(new);
	vector_sortq(this->channels, sort_fn);
	this->index = vector_get_index(this->channels, this->current);
}
