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

#include "utils.h"

bool			utils_is_valid_channame(char *name)
{
	char		*tmp;

	tmp = name;
	while (*name)
	{
		if (*name == ',' || *name == '\a' || *name == '\r' ||
				*name == '\n' || *name == ' ')
			return (false);
		name += 1;
	}
	return ((name - tmp) <= 50);
}
