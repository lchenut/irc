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

#include "argparser/argparser.h"

t_argparser			*argparser_new(char *name)
{
	t_argparser		*argparser;

	argparser = ft_calloc(sizeof(t_argparser));
	argparser->name = ft_strdup(name);
	argparser->arguments = argparser_argument_mgr_new();
	return (argparser);
}
