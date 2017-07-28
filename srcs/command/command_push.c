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

void			command_place_letter(t_command *this, char c)
{
	if (this->current->size == 510)
		return ;
	ft_memmove(this->current->line + this->curspos + 1,
			this->current->line + this->curspos,
			this->current->size - this->curspos);
	this->current->line[this->curspos] = c;
	this->curspos += 1;
	this->current->size += 1;
	line_realloc(this->current);
}
#include "data.h"
static bool		find_fn(void *data, void *ctx)
{
	char		*needle;
	char		*haystack;

	haystack = ((t_ctrl_mvmt_data *)data)->buf;
	needle = ctx;
	while (*needle)
	{
		if (*needle != *haystack)
			return (false);
		needle += 1;
		haystack += 1;
	}
	return (true);
}
static bool		find2fn(void *data, void *ctx)
{
	char		*needle;
	char		*haystack;

	haystack = ((t_ctrl_mvmt_data *)data)->buf;
	needle = ctx;
	return (ft_strcmp(haystack, needle) == 0);
}

void	(*command_get_move_fn(t_command *this))(t_command *)
{
	t_ctrl_mvmt_data	*data;

	if ((data = vector_find(data_ctrl_mvmt(), find2fn, this->buffer)))
		return (data->fn);
	return (NULL);
}

void			command_ctrl_mvmt(t_command *this, char buf)
{
	size_t		index;
	void		(*fn)(t_command *);


	index = 0;
	while (this->buffer[index])
		index += 1;
	this->buffer[index] = buf;
	if (!vector_find(data_ctrl_mvmt(), find_fn, this->buffer))
	{
		*((unsigned long *)this->buffer) = 0ul;
		return ;
	}
	if ((fn = command_get_move_fn(this)))
	{
		fn(this);
		*((unsigned long *)this->buffer) = 0ul;
	}
}

void			command_push(t_command *this, char c)
{
	if (!this->last)
	{
		this->last = line_new();
		this->current = this->last;
		this->index = vector_len(this->history);
		LOG_DEBUG("Coucou");
	}
	if (this->buffer[0] || !ft_isprint(c))
		command_ctrl_mvmt(this, c); // Match les trucs longs genre les fleches etc...
	else
		command_place_letter(this, c); // Place les lettres
	LOG_DEBUG("%s", this->current->line);
}
