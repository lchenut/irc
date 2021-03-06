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

bool			utils_is_valid_nickname(char *s)
{
	if (ft_strlen(s) > 9)
		return (false);
	if ((*s < 'A' || *s > 'Z') &&
		(*s < 'a' || *s > 'z'))
		return (false);
	s += 1;
	while (*s)
	{
		if ((*s < 'A' || *s > 'Z') &&
			(*s < 'a' || *s > 'z') &&
			(*s < '0' || *s > '9') &&
			*s != '-' && *s != '[' && *s != ']' && *s != '\\' && *s != '`' &&
			*s != '^' && *s != '{' && *s != '}')
			return (false);
		s += 1;
	}
	return (true);
}
