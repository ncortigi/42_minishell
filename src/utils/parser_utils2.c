/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:39:47 by ncortigi          #+#    #+#             */
/*   Updated: 2023/09/15 12:05:31 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	**ft_single_to_double(char **mat)
{
	int		i;
	int		j;

	i = 0;
	while (mat[i])
	{
		j = 0;
		while (mat[i][j])
		{
			if (mat[i][j] == '\'')
				mat[i][j] = '\"';
			j++;
		}
		i++;
	}
	return (mat);
}

int	ft_if_free_args(char **args, int j)
{
	if (!ft_strcmp(args[0], "export") && !ft_check_var_content(args, j, 4))
		return (1);
	else if (!ft_strcmp(args[0], "export") && !ft_check_var_content(args, j, 0))
		return (0);
	else if (!ft_strcmp(args[0], "export") && !ft_check_var_content(args, j, 1))
		return (0);
	return (2);
}

char	*ft_trim_if(char **args, int j)
{
	if (args[j][0] == '\'' && ft_strcmp(args[0], "export"))
		return (ft_strtrim(args[j], "\'", 0));
	else if (!ft_strcmp(args[0], "export") && !ft_check_var_content(args, j, 2))
		return (ft_join_and_remove(args, j, 2));
	else if (!ft_strcmp(args[0], "export") && !ft_check_var_content(args, j, 4))
		return (ft_join_and_remove(args, j, 4));
	else if (!ft_strcmp(args[0], "export") && !ft_check_var_content(args, j, 3))
		return (ft_strtrim(args[j], "\"", 0));
	else if (!ft_strcmp(args[0], "export") && !ft_check_var_content(args, j, 0))
		return (ft_join_and_remove(args, j, 0));
	else if (!ft_strcmp(args[0], "export") && !ft_check_var_content(args, j, 1))
		return (ft_join_and_remove(args, j, 1));
	else if (args[j][0] == '\"' && ft_strcmp(args[0], "export"))
		return (ft_strtrim(args[j], "\"", 0));
	return (ft_strdup(args[j]));
}

void	ft_parse(t_cmd *node, int j)
{
	char	*sup;

	if (!ft_if_free_args(node->args, j))
	{
		sup = ft_trim_if(node->args, j);
		free(node->args[j]);
		node->args[j] = sup;
		node->args = ft_mat_rm_line(j + 1, node->args);
	}
	else if (ft_if_free_args(node->args, j) == 1)
	{
		sup = ft_trim_if(node->args, j);
		free(node->args[j]);
		node->args[j] = sup;
		node->args = ft_mat_rm_line(j + 1, node->args);
		node->args = ft_mat_rm_line(j + 1, node->args);
	}
	else
	{
		sup = ft_trim_if(node->args, j);
		free(node->args[j]);
		node->args[j] = sup;
	}
}
