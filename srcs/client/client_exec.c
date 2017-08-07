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

void			client_exec_connect(t_client *this, char *cmd)
{
	LOG_INFO("Connect \\o/");
	(void)this;
	(void)cmd;
}

static char		*get_first_word(char *cmd)
{
	size_t		len;

	len = 0;
	while (cmd[len] && cmd[len] != ' ' && cmd[len] != '\t')
		len += 1;
	return (ft_strndup(cmd, len));
}

void			client_exec(t_client *this)
{
	char		*command;
	char		*first_word;
	void		(*fn)(t_client *, char *);
	
	command = command_get_line(this->command);
	command_history_push(this->command);
	if (this->connected)
	{
		write(this->sock, command, ft_strlen(command));
		write(this->sock, "\r\n", 2);
	}
	first_word = get_first_word(command);
	fn = client_get_execute_fn(first_word);
	if (fn)
		fn(this, command);
	free(first_word);
	visual_clear_prompt(this->visual);
	free(command);
}
