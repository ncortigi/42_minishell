/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:51:19 by ncortigi          #+#    #+#             */
/*   Updated: 2023/09/15 11:16:31 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// function to free data struct
void	ft_freedata(t_data *data)
{
	clear_history();
	ft_freemat(data->envp);
	if (data->export)
		ft_freemat(data->export);
	free(data);
}

void	ft_freered(t_red **red)
{
	t_red	*tmp;
	t_red	*head;

	head = *red;
	while (head)
	{
		tmp = head->next;
		if (head->out_fd)
			free(head->out_fd);
		if (head->in_fd)
			free(head->in_fd);
		free(head);
		head = tmp;
	}
	free(red);
}

// function to free the cmd struct
void	ft_freecmd(t_cmd *cmd)
{
	if (cmd && cmd->path)
		free(cmd->path);
	if (cmd && cmd->args)
		ft_freemat(cmd->args);
	if (cmd && cmd->redir)
		ft_freered(cmd->redir);
	if (cmd)
		free(cmd);
}

void	ft_freecmdast(t_cmd **cmd)
{
	t_cmd	*tmp;
	t_cmd	*head;

	head = *cmd;
	while (head)
	{
		tmp = head->next;
		ft_freecmd(head);
		head = tmp;
	}
	free(cmd);
}

void	ft_reset_cmdline(t_data *data)
{
	dup2(data->original_std_fd[0], 0);
	dup2(data->original_std_fd[1], 1);
}
