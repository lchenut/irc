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

void			buffer_dump(t_buffer *this)
{
	ft_putstr("BUFFER >\e[35m");
	ft_putstr(ft_strrep_unprint_char(this->buffer));
	ft_putstr("\e[m<\nSTART ");
	ft_putnbr(this->start);
	ft_putstr("\nEND   ");
	ft_putnbr(this->end);
	ft_putstr("\nSIZE  ");
	ft_putnbr(this->size);
	ft_putchar('\n');
}
