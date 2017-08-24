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

#ifndef UTILS_H
# define UTILS_H

# include "basics.h"

# define IRC_NAME "irc.42.fr"

char			*utils_concat(char *fmt, ...);

bool			utils_is_valid_nickname(char *s);
bool			utils_is_valid_key(char *s);
bool			utils_is_valid_username(char *s);
bool			utils_is_valid_channame(char *s);

#endif
