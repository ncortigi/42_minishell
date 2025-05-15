/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:22:12 by ncortigi          #+#    #+#             */
/*   Updated: 2023/09/14 19:41:24 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_env_search(char *var, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], var, ft_strlen(var)) == 0 && \
			env[i][ft_strlen(var)] == '=')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_env_varname_search(char *var, char **matrix)
{
	int		i;
	int		j;
	char	*var_name;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j] != '=' && matrix[i][j])
			j++;
		if (j == (int)ft_strlen(matrix[i]) && !ft_strchr(matrix[i], '='))
			var_name = ft_strdup(matrix[i]);
		else
			var_name = ft_substr(matrix[i], 0, j);
		if (ft_strncmp(var_name, var, ft_strlen(var_name)) == 0)
		{
			free(var_name);
			break ;
		}
		free(var_name);
		i++;
	}
	return (i);
}
