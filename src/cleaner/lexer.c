/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:39:09 by everonel          #+#    #+#             */
/*   Updated: 2023/09/14 13:09:46 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	**ft_lex_input(char *line, int j)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = (char **)ft_calloc(ft_strlen(line) + 1, sizeof(char *));
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			i++;
		else if (line[i] == '|')
		{
			tmp[j] = ft_strdup("|");
			i++;
			j++;
		}
		else if (!ft_check_clean(line[i]))
		{
			tmp[j] = ft_clean(line, &i);
			j++;
		}
	}
	tmp[j] = NULL;
	if (!tmp[0])
		return (free(tmp), NULL);
	return (ft_matdup(tmp, 1));
}

// function to clean a single word
char	*ft_wdcleaner(char *line, char *token, int *sum_len)
{
	int		i;
	int		len;
	char	*new;

	i = 0;
	len = ft_wdlen(line, token);
	new = (char *)ft_calloc(sizeof(char), len + 1);
	while (i++ < len)
		new[i - 1] = line[i - 1];
	if (line[i - 1] == ' ')
	{
		if (new[i - 2] == '\'' || new[i - 2] == '\"')
			new = ft_strins(new, " ", ft_strlen(new) - 1, 1);
		else
			new = ft_strjoin(new, " ", 1);
	}
	*sum_len += len;
	return (new);
}

int	ft_wdlen(char *line, char *token)
{
	int		i;
	char	c;

	c = line[0];
	i = 1;
	if (ft_strcmp("\'\"", token) == 0)
	{
		while (line[i] && line[i] != c)
			i++;
		return (i + 1);
	}
	else
	{
		while (line[i] && !ft_strchr(token, line[i]))
			i++;
		return (i);
	}
	return (i);
}

char	*ft_redcleaner(char *line, int *sum_len)
{
	char	*new;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (line[i] && (line[i] == '<' || line[i] == '>'))
		i++;
	new = (char *)ft_calloc(sizeof(char), i + 1);
	while (len < i)
	{
		new[len] = line[len];
		len++;
	}
	*sum_len += len;
	return (new);
}
