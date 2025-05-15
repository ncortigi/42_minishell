/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:54:39 by ncortigi          #+#    #+#             */
/*   Updated: 2023/09/14 13:16:06 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_check_clean(char c)
{
	if (c == '>' || c == '<')
		return (0);
	else if (c == '\'' || c == '\"')
		return (0);
	else
		return (0);
	return (1);
}

char	*ft_clean(char *line, int *i)
{
	if (line[*i] == '>' || line[*i] == '<')
		return (ft_redcleaner(line + *i, i));
	else if (line[*i] == '\'' || line[*i] == '\"')
		return (ft_wdcleaner(line + *i, "\'\"", i));
	else
		return (ft_wdcleaner(line + *i, " \t\'\"|><", i));
}
