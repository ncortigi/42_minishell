/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expacker.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:03:38 by everonel          #+#    #+#             */
/*   Updated: 2023/09/14 22:37:07 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_check_dollar(char *cmd, t_data *data)
{
	char	**mat;
	char	*ret;

	if (cmd[0] == '$' && cmd[1])
	{
		mat = ft_split(cmd, '$');
		ret = ft_expander(mat, data, 0);
		ft_freemat(mat);
		return (ret);
	}
	else if (cmd[1] == '$' && cmd[2] != '\"')
	{
		mat = ft_split(cmd, '$');
		ret = ft_expander(mat, data, 1);
		ft_freemat(mat);
		return (ret);
	}
	else
		return (ft_strdup("$"));
}

// function to check if the command is valid and to expand it
int	ft_expacker(char **cmd, t_data *data)
{
	char	*tmp;
	int		i;

	i = 0;
	while (cmd[i])
	{
		if ((cmd[i][0] == '>' || cmd[i][0] == '<') && \
			ft_syntax_check_redir(cmd, i) != 0)
			return (258);
		if ((cmd[i][0] == '\'' || cmd[i][0] == '\"') && \
			ft_syntax_check_quotes(cmd, i) != 0)
			return (258);
		if ((cmd[i][0] == '\"' || cmd[i][0] != '\'') && ft_strchr(cmd[i], '$'))
		{
			tmp = ft_strdup(cmd[i]);
			free (cmd[i]);
			cmd[i] = ft_check_dollar(tmp, data);
			free(tmp);
		}
		if ((cmd[i][0] == '|' && cmd[i + 1] && cmd[i + 1][0] == '|') || \
			(i == 0 && cmd[i][0] == '|'))
			return (ft_print_error(1), 2);
		i++;
	}
	return (0);
}

// ______________GESTIRE EXIT_____________________
int	ft_syntax_check_redir(char **cmd, int pos)
{
	int	i;

	i = 0;
	while (cmd[pos][i] && (cmd[pos][i] == '>' || cmd[pos][i] == '<'))
		i++;
	if (i > 2)
	{
		if (i == 3)
			return (perror("syntax error near unexpected token `newline'\n"), \
				258);
		if (i >= 4)
			return (perror("syntax error near unexpected token `newline'\n"), \
				258);
	}
	if (i == 2 && cmd[pos][0] != cmd[pos][1])
		return (perror("syntax error near unexpected token `newline'\n"), 258);
	if (cmd[pos + 1][0] == '>' || cmd[pos + 1][0] == '<' || \
		cmd[pos + 1][0] == '|')
		return (perror("syntax error near unexpected token `newline'\n"), 258);
	if (!cmd[pos + 1])
		return (perror("syntax error near unexpected token `newline'\n"), 258);
	return (0);
}

// ______________GESTIRE EXIT_____________________
int	ft_syntax_check_quotes(char **cmd, int pos)
{
	int	i;

	i = 0;
	while (cmd[pos][i])
		i++;
	if (cmd[pos][i - 1] != cmd[pos][0])
		return (perror("syntax error near unexpected token `newline'\n"), 258);
	return (0);
}

// ______________GESTIRE EXIT_____________________
int	ft_syntax_check_special_char(char **cmd, int pos)
{
	int	i;

	i = 0;
	if (ft_strnstr(cmd[pos], "&&", 2) || ft_strnstr(cmd[pos], "${", 2) || \
		ft_strnstr(cmd[pos], "||", 2) || ft_strnstr(cmd[pos], "$(", 2) || \
		ft_strnstr(cmd[pos], "$$", 2) || ft_strnstr(cmd[pos], "$#", 2))
		return (perror("niente bonus per te\n"), 500);
	while (cmd[pos][i])
	{
		if (cmd[pos][i] == '\\' || cmd[pos][i] == ';' || cmd[pos][i] == '&' || \
			(cmd[pos][i] == '$' && ft_isdigit(cmd[pos][i + 1])))
			return (perror("niente bonus per te\n"), 500);
		i++;
	}
	return (0);
}
