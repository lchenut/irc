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

#include "replies.h"
#include "utils.h"

static char		*reply_to_string_concat(char *src, const char *dst)
{
	src[0] = ' ';
	src += 1;
	while (*dst)
	{
		*src = *dst;
		src += 1;
		dst += 1;
	}
	src[0] = 0;
	return (src);
}

static void		iter_len_fn(void *data, void *ctx)
{
	*((size_t *)ctx) += ft_strlen(data) + 1;
}

static void		iter_concat_fn(void *data, void *ctx)
{
	*((char **)ctx) = reply_to_string_concat(*((char **)ctx), data);
}

char			*reply_to_string(t_rpl_cnt *this)
{
	size_t		len;
	char		*ret;
	char		*tmp;

	len = ft_strlen(this->command);
	vector_iter(this->params, iter_len_fn, &len);
	ret = ft_strnew(len);
	tmp = utils_concat(ret, this->command);
	vector_iter(this->params, iter_concat_fn, &tmp);
	return (ret);
}
