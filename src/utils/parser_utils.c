/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:15:38 by everonel          #+#    #+#             */
/*   Updated: 2023/09/15 12:05:14 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// funtion to create a new t_cmd node
t_cmd	*ft_cmd_node_gen(char **cmd_mat, int i, t_data *data)
{
	t_cmd	*node;
	t_red	*redir_node;
	char	*line;

	line = ft_strtrim(cmd_mat[0], " \'\"", 0);
	node = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	node->args = ft_matins_str(NULL, line, 0);
	free(line);
	cmd_mat = ft_submat(cmd_mat, 1, ft_matlen(cmd_mat), 1);
	while (cmd_mat && cmd_mat[i])
	{
		node->args = ft_matjoin(node->args, ft_getcmd_args(cmd_mat + i, &i), 3);
		if (cmd_mat[i] && (cmd_mat[i][0] == '<' || cmd_mat[i][0] == '>'))
		{
			node->redir = (t_red **)ft_calloc(sizeof(t_red *), 1);
			redir_node = ft_redir_new(node, cmd_mat, &i);
			ft_redir_add_back(node->redir, redir_node);
		}
		else
			node->redir = NULL;
	}
	node->path = ft_get_cmd_path(node->args[0], data);
	node->next = NULL;
	ft_freemat(cmd_mat);
	return (node);
}

// function to add a t_cmd node to the t_cmd *list
void	ft_cmd_ast_add_back(t_cmd **cmnd_lst, t_cmd *node)
{
	t_cmd	*tmp;

	tmp = *cmnd_lst;
	if (!tmp)
		*cmnd_lst = node;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
}

char	**ft_mat_rm_line(int rm_line, char **mat)
{
	int		i;
	int		j;
	char	**new;

	i = 0;
	while (mat[i])
		i++;
	new = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	j = 0;
	while (mat[i])
	{
		if (i != rm_line)
		{
			new[j] = ft_strdup(mat[i]);
			j++;
		}
		i++;
	}
	new[j] = 0;
	ft_freemat(mat);
	return (new);
}
