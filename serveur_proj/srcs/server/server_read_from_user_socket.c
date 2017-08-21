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

#include "server.h"
#include "user.h"

static void	cmd_lst_push_back(t_server *this, t_user *user, char *line)
{
	t_cmd_lst	*cmd_lst;

	cmd_lst = ft_calloc(sizeof(t_cmd_lst));
	cmd_lst->user = user;
	cmd_lst->line = ft_strdup(line);
	lst_push_back(this->cmd_lst, cmd_lst);
}

static void	exec_loop(t_server *this, t_user *user)
{
	t_cmd_lst	*cmd_lst;

	while ((cmd_lst = lst_pop_front(this->cmd_lst)))
	{
		user_exec_command(user, cmd_lst->line, this);
		free(cmd_lst->line);
		free(cmd_lst);
	}
}

static void	server_read_loop(t_server *this, t_user *user)
{
	char			*line;

	line = NULL;
	while ((line = buffer_pop_line(user->buffer)))
	{
		if (!ft_strchr(line, '\n'))
		{
			user->flush_sock = true;
			free(line);
			break ;
		}
		user->msg_nb += 1;
		cmd_lst_push_back(this, user, line);
		free(line);
	}
	exec_loop(this, user);
}

void		server_read_from_user_socket(t_server *this, int csocket)
{
	t_user	*user;
	int		flush_ret;

	user = server_get_user_from_socket(this, csocket);
	if (user == NULL)
		return ;
	if (user->flush_sock)
	{
		flush_ret = buffer_flush_fd(user->buffer, user->socket);
		if (flush_ret <= 0)
		{
			server_delete_user_from_socket(this, csocket);
			return ;
		}
		else if (flush_ret == 1)
			user->flush_sock = false;
		else
			return ;
	}
	else if (!buffer_read_from_fd(user->buffer, user->socket))
	{
		user_exec_quit(user, NULL, this);
		return ;
	}
	server_read_loop(this, user);
}
