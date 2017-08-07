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
#include "xstdlib.h"

/*
** 0: Unknown error
** 1: Address family for nodename not supported
** 2: Temporary failure in name resolution
** 3: Invalid value for ai_flags
** 4: Non-recoverable failure in name resolution
** 5: ai_family not supported
** 6: Memory allocation failure
** 7: No address associated with nodename
** 8: nodename nor servname provided, or not known
** 9: servname not supported for ai_socktype
** 10: ai_socktype not supported
** 11: System error
** 12: Bad hints
** 13: ai_protocol not supported
** 14: argument buffer overflow
*/

static char			g_gai_strerror_ret[1024];
static const char	*g_gai_strerror[] =
{
	"Unknown error",
	"Address family for nodename not supported",
	"Temporary failure in name resolution",
	"Invalid value for ai_flags",
	"Non-recoverable failure in name resolution",
	"ai_family not supported",
	"Memory allocation failure",
	"No address associated with nodename",
	"nodename nor servname provided, or not known",
	"servname not supported for ai_socktype",
	"ai_socktype not supported",
	"System error",
	"Bad hints",
	"ai_protocol not supported",
	"argument buffer overflow"
};
static const int	g_gai_nerr = 15;

static void		set_num(int n)
{
	char		*num;
	char		*save;
	char		*tmp;

	num = ft_itoa(n);
	save = num;
	tmp = g_gai_strerror_ret;
	while (*num)
	{
		*tmp = *num;
		tmp += 1;
		num += 1;
	}
	tmp[0] = ':';
	tmp[1] = ' ';
	tmp[2] = '\0';
	free(save);
}

char			*utils_gai_strerror(int error)
{
	set_num(error);
	if (error < 0 || error > g_gai_nerr || g_gai_strerror[error] == NULL)
	{
		error = 0;
	}
	ft_strcat(g_gai_strerror_ret, g_gai_strerror[error]);
	LOG_DEBUG("%s", g_gai_strerror_ret);
	return (g_gai_strerror_ret);
}
