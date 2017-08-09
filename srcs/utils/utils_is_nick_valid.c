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

bool			utils_is_valid_nick(char *nick)
{
	size_t		index;

	index = 1;
	if (!ft_isalpha(*nick))
		return (false);
	while (nick[index] && index < 10)
	{
		if (!ft_isalnum(nick[index]) && !utils_isspecial(nick[index]))
			return (false);
		index += 1;
	}
	return (nick[index] == '\0');
}
