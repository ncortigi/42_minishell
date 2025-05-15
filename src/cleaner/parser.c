/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:47:01 by everonel          #+#    #+#             */
/*   Updated: 2023/09/15 12:10:31 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// function to initialize the command ast
t_cmd	**ft_parser(char **lex_cmd, int i, int j, t_data *data)
{
	t_cmd	**cmd_ast;
	t_cmd	*node;
	char	**cmd_mat;

	cmd_ast = (t_cmd **)ft_calloc(sizeof(t_cmd *), 1);
	while (lex_cmd[i])
	{
		j = 1;
		cmd_mat = ft_dividetimpera(lex_cmd, &i);
		cmd_mat = ft_check_heredoc(cmd_mat);
		if (cmd_mat[0][0] == '<' || cmd_mat[0][0] == '>')
			cmd_mat = ft_matins_str(cmd_mat, "cat", 0);
		node = ft_cmd_node_gen(cmd_mat, 0, data);
		ft_cmd_ast_add_back(cmd_ast, node);
		while (node->args[j])
		{
			if (!ft_strcmp(node->args[0], "export"))
				node->args = ft_single_to_double(node->args);
			else if (ft_strcmp(node->args[0], "echo"))
				node->args[j] = ft_strtrim(node->args[j], " ", 1);
			ft_parse(node, j);
			j++;
		}
	}
	return (cmd_ast);
}

char	**ft_choose_heredoc(char **cmd_mat, int i)
{
	if (i == 0 && !cmd_mat)
		cmd_mat = ft_matins_str(cmd_mat, ".heredoc", i);
	else if (i != 0 && !cmd_mat[i])
		cmd_mat = ft_matins_str(cmd_mat, ".heredoc", i);
	else if ((i != 0 || !cmd_mat[i]) && (cmd_mat[i][0] == '<' || \
		cmd_mat[i][0] == '>'))
		cmd_mat = ft_matins_str(cmd_mat, ".heredoc", i);
	else if (cmd_mat[i][0] != '<' && cmd_mat[i][0] != '>')
		cmd_mat = ft_matins_str(cmd_mat, ".heredoc", i + 1);
	else if (cmd_mat[0][0] != '<' && cmd_mat[0][0] != '>')
		cmd_mat = ft_matins_str(cmd_mat, ".heredoc", i);
	else
	{
		cmd_mat = ft_matins_str(cmd_mat, ".heredoc", i);
		cmd_mat = ft_matins_str(cmd_mat, "cat", i);
	}
	return (cmd_mat);
}

char	**ft_check_heredoc(char **cmd_mat)
{
	int	i;

	i = 0;
	while (cmd_mat && cmd_mat[i])
	{
		if (!ft_strcmp(cmd_mat[i], "<<"))
		{
			if (!ft_here_doc(ft_strtrim(cmd_mat[i + 1], " ", 0)))
				return (NULL);
			cmd_mat = ft_matdelstr_idx(cmd_mat, cmd_mat[i], i);
			cmd_mat = ft_matdelstr_idx(cmd_mat, cmd_mat[i], i);
			cmd_mat = ft_choose_heredoc(cmd_mat, i);
		}
		i++;
	}
	return (cmd_mat);
}

//cat << EOF e << EOF vanno in seg fault per un problema agli if :(
char	**ft_dividetimpera(char **cmd_mat, int *pos)
{
	char	**cmd;
	int		j;
	int		i;

	j = 0;
	i = 0;
	while (cmd_mat[*pos + i] != NULL && \
		ft_strcmp(cmd_mat[*pos + i], "|"))
		i++;
	cmd = (char **)ft_calloc(i + 1, sizeof(char *));
	while (j < i)
	{
		cmd[j] = ft_strdup(cmd_mat[*pos + j]);
		j++;
	}
	if (cmd_mat[*pos + i])
		i++;
	*pos += i;
	return (cmd);
}
