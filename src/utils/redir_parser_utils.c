/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_parser_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:21:51 by ncortigi          #+#    #+#             */
/*   Updated: 2023/09/15 12:05:50 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// function to create a new t_red node
t_red	*ft_redir_new(t_cmd *cmd, char **mat, int *pos)
{
	t_red	*node;

	(void) cmd;
	node = (t_red *)ft_calloc(1, sizeof(t_red));
	if (mat[*pos][0] == '>')
		ft_redir_new_grt(mat, *pos, node, cmd);
	else if (mat[*pos][0] == '<' && !mat[*pos][1])
		ft_redir_new_lwr(mat, *pos, node);
	*pos += 2;
	node->next = NULL;
	return (node);
}

void	ft_redir_new_grt(char **mat, int pos, t_red *redir, t_cmd *cmd)
{
	if (mat[pos][1])
		redir->token = 2;
	else
		redir->token = 1;
	if (pos != 0 && ft_strcmp(cmd->args[0], "echo") != 0)
		redir->in_fd = ft_strtrim(mat[pos - 1], " ", 0);
	else
		redir->in_fd = NULL;
	redir->out_fd = ft_strtrim(mat[pos + 1], " ", 0);
}

void	ft_redir_new_lwr(char **mat, int pos, t_red *redir)
{
	if (!mat[pos][1])
	{
		redir->token = -1;
		redir->in_fd = ft_strtrim(mat[pos + 1], " ", 0);
		if (pos != 0)
			redir->out_fd = ft_strtrim(mat[pos - 1], " ", 0);
		else
			redir->out_fd = NULL;
	}
}

// function to add a t_red node to the t_red *list
void	ft_redir_add_back(t_red **redir, t_red *node)
{
	t_red	*tmp;

	tmp = *redir;
	if (!tmp)
		*redir = node;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
}
