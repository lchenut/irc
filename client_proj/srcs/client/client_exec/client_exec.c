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

static char		*get_first_word(char *cmd)
{
	size_t		len;

	len = 0;
	while (cmd[len] && cmd[len] != ' ' && cmd[len] != '\t')
		len += 1;
	return (ft_strndup(cmd, len));
}

static void		print_error_msg(t_client *this, char *first_word)
{
	visual_dump_date(this->visual, " HOME ");
	visual_print_red(this->visual, first_word, " HOME ");
	visual_print_red(this->visual, ": Unknown command", " HOME ");
	visual_print_newline(this->visual, " HOME ");
}

void			client_exec(t_client *this)
{
	char		*command;
	char		*begin;
	char		*first_word;
	void		(*fn)(t_client *, char *);

	if (!(command = command_get_line(this->command)))
		return ;
	begin = command;
	while (*begin && (*begin == ' ' || *begin == '\t'))
		begin += 1;
	command_history_push(this->command);
	first_word = get_first_word(begin);
	if ((fn = client_get_execute_fn(first_word)))
		fn(this, command);
	else if (first_word[0] == '/')
		print_error_msg(this, first_word);
	else if (this->connected && *command)
		client_exec_privmsg_soft(this, command);
	visual_clear_prompt(this->visual);
	free(first_word);
	free(command);
}
