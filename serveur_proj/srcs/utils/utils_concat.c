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

#include <stdarg.h>
#include "utils.h"

static void	concat_arg(char *buf, va_list ap, int *index_buf, int *index_fmt)
{
	char		*arg;
	int			index_arg;

	arg = va_arg(ap, char *);
	index_arg = 0;
	while (*index_buf < 509 && arg[index_arg])
	{
		buf[*index_buf] = arg[index_arg];
		*index_buf += 1;
		index_arg += 1;
	}
	*index_fmt += 2;
}

static void	concat_fmt(char *buf, char *fmt, int *index_buf, int *index_fmt)
{
	buf[*index_buf] = fmt[*index_fmt];
	*index_buf += 1;
	*index_fmt += 1;
}

char		*utils_concat(char *fmt, ...)
{
	char	buf[512];
	int		index_buf;
	int		index_fmt;
	va_list	ap;

	va_start(ap, fmt);
	index_buf = 0;
	index_fmt = 0;
	while (index_buf < 509 && fmt[index_fmt])
	{
		if (fmt[index_fmt] == '%' && fmt[index_fmt + 1] == 's')
			concat_arg(buf, ap, &index_buf, &index_fmt);
		else
			concat_fmt(buf, fmt, &index_buf, &index_fmt);
	}
	buf[index_buf] = '\r';
	buf[index_buf + 1] = '\n';
	buf[index_buf + 2] = '\0';
	return (ft_strdup(buf));
}
