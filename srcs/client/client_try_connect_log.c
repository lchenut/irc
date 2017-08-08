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

static char			*concat_str(char *s1, char *s2)
{
	while (*s2)
	{
		*s1 = *s2;
		s1 += 1;
		s2 += 1;
	}
	*s1 = 0;
	return (s1);
}

void				client_try_connect_log(t_client *this, int af_family)
{
	char			*tmp;
	char			*s;

	if (af_family == AF_INET)
	{
		LOG_INFO("Try connect ipv4");
	}
	else
	{
		LOG_INFO("Try connect ipv6");
	}
	tmp = malloc(ft_strlen(this->address) + ft_strlen(this->port) + 20);
	s = concat_str(tmp, "Try connect to: ");
	s = concat_str(s, this->address);
	s = concat_str(s, " ");
	concat_str(s, this->port);
	client_print_and_refresh(this, visual_print_bold, tmp);
	free(tmp);
}
