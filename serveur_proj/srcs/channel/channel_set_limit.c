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

#include "channel.h"

void			channel_set_limit(t_channel *this, char *limit)
{
	int			ilimit;

	if (!limit || !ft_strisnum(limit))
		return ;
	ilimit = ft_atoi(limit);
	if (ilimit <= 0)
		return ;
	this->limit = ilimit > 100 ? 100 : ilimit;
}
