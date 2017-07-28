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

#include "line.h"

void			line_realloc(t_line *this)
{
	char		*tmp;

	if (this->size >= this->total)
	{
		tmp = ft_strnew(this->total << 1);
		ft_strcpy(tmp, this->line);
		free(this->line);
		this->line = tmp;
		this->total <<= 1;
	}
}
