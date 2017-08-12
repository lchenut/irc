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

void			client_exec_privmsg_soft(t_client *this, char *cmd)
{
	t_visual_channel	*channel;
	
	channel = this->visual->current;
	if (!ft_strcmp(channel->name, "HOME"))
	{
		visual_dump_date(this->visual, "HOME");
		visual_print_red(this->visual, "Cannot send message in HOME", "HOME");
		visual_print_newline(this->visual, "HOME");
		return ;
	}
	client_write_sock(this, "PRIVMSG ");
	client_write_sock(this, channel->name);
	client_write_sock(this, " :");
	client_write_sock(this, cmd);
	client_write_sock(this, "\r\n");
	visual_dump_date(this->visual, channel->name);
	visual_print_green(this->visual, this->nick, channel->name);
	visual_print_green(this->visual, ": ", channel->name);
	visual_print_channel(this->visual, cmd, channel->name);
	visual_print_newline(this->visual, channel->name);
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
	fn = client_get_execute_fn(first_word);
	if (fn)
		fn(this, command);
	else if (first_word[0] == '/')
	{
		visual_dump_date(this->visual, "HOME");
		visual_print_red(this->visual, first_word, "HOME");
		visual_print_red(this->visual, ": Unknown command", "HOME");
		visual_print_newline(this->visual, "HOME");
	}
	else if (this->connected && *command)
	{
		client_exec_privmsg_soft(this, command);
	}
	visual_clear_prompt(this->visual);
	free(first_word);
	free(command);
}
