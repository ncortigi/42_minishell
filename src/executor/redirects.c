/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 01:20:29 by everonel          #+#    #+#             */
/*   Updated: 2023/09/14 22:37:19 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_print_error(int i)
{
	if (!i)
		perror("Command not found");
	else
		write(2, "syntax error near unexpected token `newline'\n", 45);
}

int	ft_redir(t_red **redir, t_data *data)
{
	t_red	*head;

	head = *redir;
	while (head) 
	{
		if (head->token > 0)
			return (ft_redir_grt(head, data));
		else if (head->token < 0) 
			return (ft_redir_lwr(head, data));
		head = head->next;
	}
	return (0);
}

void	ft_error_redir(t_data *data)
{
	perror("Error opening file");
	ft_freecmdast(data->cmd_ast);
	ft_freedata(data);
	exit(1);
}

int	ft_redir_grt(t_red *redir, t_data *data)
{
	int	fd;

	fd = -1;
	if (redir->in_fd)
	{
		fd = open(redir->in_fd, O_RDONLY);
		if (fd != -1)
		{
			dup2(fd, 0);
			close(fd);
		}
	}
	if (redir->token == 1)
		fd = open(redir->out_fd, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (redir->token == 2) 
		fd = open(redir->out_fd, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		ft_error_redir(data);
	dup2(fd, 1);
	close(fd);
	return (0);
}

int	ft_redir_lwr(t_red *redir, t_data *data)
{
	int	fd;

	fd = -1;
	fd = open(redir->in_fd, O_RDONLY);
	if (fd == -1)
		ft_error_redir(data);
	dup2(fd, 0);
	close(fd);
	if (redir->out_fd)
	{
		fd = open(redir->out_fd, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			ft_error_redir(data);
		dup2(fd, 1);
		close(fd);
	}
	return (0);
}
