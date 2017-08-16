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

#include "stringft.h"

bool			utils_is_valid_username(char *s)
{
	if (*s == 0 || ft_strlen(s) > 19)
		return (false);
	while (*s)
	{
		if (*s == ' ' || *s == '\n' || *s == '\r' || *s == '@' || *s >= 0x7f)
			return (false);
		s += 1;
	}
	return (true);
}
