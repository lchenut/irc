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

t_line			*line_copy(t_line *this)
{
	t_line		*copy;

	copy = ft_calloc(sizeof(t_line));
	copy->copy = ft_strdup(this->line);
	copy->line = ft_strnew(this->total);
	ft_strcat(copy->line, this->line);
	copy->size = this->size;
	copy->total = this->total;
	return (copy);
}
