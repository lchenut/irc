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

#include "command.h"

char			*command_get_line_scaled(t_command *this)
{
	char		*ret;
	size_t		tmp;

	tmp = 0;
	while (this->curspos >= tmp)
		tmp += this->winsize;
	tmp -= this->winsize;
	ret = ft_strndup(this->current->line + tmp, this->winsize);
	return (ret);
}
