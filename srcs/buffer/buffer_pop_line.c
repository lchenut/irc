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

#include "buffer.h"

static char		*pop_line(t_buffer *this, int count)
{
	char		*ret;
	int			index_ret;

	ret = ft_strnew(count);
}

char			*buffer_pop_line(t_buffer *this)
{
	int			count;
	int			index;
	char		*ret;
	bool		found;

	count = 0;
	index = (int)this->start;
	found = false;
	ret = NULL;
	while (this->buffer[index])
	{
		if (this->buffer[index] == '\n')
		{
			found = true;
			break ;
		}
		index += 1;
		count += 1;
		if (index == this->total)
			index = 0;
		if (count == this->total)
			break ;
	}
	if (!found && this->remainder)
		ret = pop_line(this, this->total);
	else if (found)
		ret = pop_line(this, count);
	return (ret);
	char		*s;

	index = 0;
	s = this->buffer;
	while (s[index])
	{
		if (s[index] == '\r' && s[index + 1] == '\n')
			break ;
		index += 1;
	}
	if (!s[index])
		return (NULL);
	s = ft_strndup(this->buffer, index);
	ft_memmove(this->buffer, this->buffer + index + 2, this->total - index - 2);
	this->current = this->current - index - 2;
	return (s);
}
