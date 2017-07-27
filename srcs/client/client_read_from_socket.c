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

#include "client.h"

static char		*rep_nl(char *s)
{
	char		*ret;
	char		*tmp;

	if (!s)
		return ("(null)");
	ret = ft_strnew(ft_strlen(s) << 1);
	tmp = ret;
	while (*s)
	{
		if (*s == '\n') { *tmp = '\\'; tmp += 1; *tmp = 'n'; }
		else if (*s == '\r') { *tmp = '\\'; tmp += 1; *tmp = 'r'; }
		else { *tmp = *s; }
		tmp += 1; s += 1;
	}
	return (ret);
}

void			client_read_from_socket(t_client *this, int fd)
{
	char		*rep;

	if (!this->socket_buf)
		this->socket_buf = buffer_new(fd);
	buffer_read_from_fd(this->socket_buf, fd);
	buffer_dump(this->socket_buf);
	printf("LINE   >\e[34m%s\e[m<\n", rep_nl((rep = buffer_pop_line(this->socket_buf))));
	if (rep && !ft_strchr(rep, '\n'))
		buffer_flush_fd(this->socket_buf, fd);
	free(rep);
}
