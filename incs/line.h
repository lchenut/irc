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

#ifndef LINE_H
# define LINE_H

# define DFL_LINE_SIZE 64

# include "basics.h"

typedef struct		s_line
{
	char			*line;
	char			*copy;
	size_t			total;
	size_t			size;
}					t_line;

t_line				*line_new(void);
void				line_del(t_line *this);

t_line				*line_copy(t_line *this);
void				line_reset_line(t_line *this);

void				line_realloc(t_line *this);

#endif
