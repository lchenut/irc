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

#include "channel.h"

t_channel		*channel_new(char *name, char *key)
{
	t_channel	*this;

	this = ft_calloc(sizeof(t_channel));
	this->name = ft_strdup(name);
	this->key = key ? ft_strdup(key) : key;
	this->mode.private = false;
	this->mode.secret = false;
	this->mode.oninv = false;
	this->mode.topiclock = false;
	this->mode.msgrestrict = false;
	this->mode.moderate = false;
	this->limit = 10;
	this->users = vector_new();
	this->chanop = vector_new();
	return (this);
}
