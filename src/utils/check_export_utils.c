/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_export_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:15:06 by ncortigi          #+#    #+#             */
/*   Updated: 2023/09/15 12:12:25 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_check_exportvar_int(char *arg)
{
	int	i;

	i = 0;
	if (!ft_strncmp(arg, "=", 1))
		return (1);
	if (arg[i] >= 48 && arg[i] <= 57)
		return (1);
	while (arg[i] && arg[i] != '=')
	{
		if (arg[i] < 48 || (arg[i] > 57 && arg[i] < 61) || \
			(arg[i] > 61 && arg[i] < 65) || \
			(arg[i] > 90 && arg[i] < 95) || \
			(arg[i] > 95 && arg[i] < 97) || arg[i] > 122)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_return_trim(char **args, int i)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strtrim(args[i], "\"", 0);
	tmp2 = ft_strtrim(args[i + 2], "\"", 0);
	return (ft_strjoin(tmp, ft_strjoin(args[i + 1], tmp2, 2), 3));
}

char	*ft_join_and_remove(char **args, int i, int what)
{
	char	*tmp;
	char	*tmp2;

	if (!what)
	{
		tmp = ft_strtrim(args[i + 1], "\"", 0);
		return (ft_strjoin(args[i], tmp, 2));
	}
	else if (what == 1)
	{
		tmp = ft_strjoin(args[i], args[i + 1], 0);
		return (ft_strtrim(args[i], "\"", 0));
	}
	else if (what == 2)
	{
		tmp = ft_strtrim(args[i], "\"", 0);
		tmp2 = ft_strtrim(tmp, " ", 0);
		free(tmp);
		return (tmp2);
	}
	else if (what == 3)
		return (ft_strtrim(args[i], "\"", 0));
	else
		return (ft_return_trim(args, i));
}

int	ft_double_check(char **args, int i, int k)
{
	char	*tmp;

	if (!k)
	{
		if (ft_strchr(args[i], '\"') && !args[i + 1])
		{
			tmp = ft_strtrim(args[i], "\"", 0);
			if (!ft_check_exportvar_int(tmp))
			{
				free(tmp);
				return (0);
			}
			free(tmp);
		}
	}
	else
	{
		if (ft_strchr(args[i], '\"') && !ft_strchr(args[i], ' ') && \
			args[i + 1] && !ft_strcmp(args[i + 1], "=") && args[i + 2]) 
			return (0);
	}
	return (1);
}

int	ft_check_var_content(char **args, int i, int check)
{
	if (!check)
	{
		if (ft_strchr(args[i], '=') && !ft_strchr(args[i], ' ') && \
			args[i + 1] && ft_strchr(args[i + 1], '\"'))
			return (0);
	}
	else if (check == 1)
	{
		if (ft_strchr(args[i], '\"') && !ft_strchr(args[i], ' ') && \
			args[i + 1] && ft_strchr(args[i + 1], '='))
			return (0);
	}
	else if (check == 2)
	{
		if (ft_strchr(args[i], '\"') && ft_strchr(args[i], ' '))
			return (0);
	}
	else if (check == 3)
		return (ft_double_check(args, i, 0));
	else
		return (ft_double_check(args, i, 1));
	return (1);
}
