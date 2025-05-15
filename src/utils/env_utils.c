/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:30:52 by ncortigi          #+#    #+#             */
/*   Updated: 2023/09/09 17:22:51 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_env_change(t_data *data, char *var, char *full_var)
{
	int	i;
	int	line;

	i = 0;
	line = ft_env_varname_search(var, data->envp);
	while (data->envp[i])
	{
		if (i == line)
		{
			free(data->envp[i]);
			data->envp[i] = ft_strdup(full_var);
		}
		i++;
	}
}

char	**ft_env_remove(char *var, t_data *data)
{
	int		i;
	int		j;
	int		rm_line;
	char	**new_env;

	i = 0;
	rm_line = ft_env_varname_search(var, data->envp);
	while (data->envp[i])
		i++;
	new_env = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	j = 0;
	while (data->envp[i])
	{
		if (i != rm_line)
		{
			new_env[j] = ft_strdup(data->envp[i]);
			j++;
		}
		i++;
	}
	new_env[j] = 0;
	ft_freemat(data->envp);
	return (new_env);
}

char	**ft_env_add(t_data *data, char *var)
{
	int		i;
	char	**new_env;

	i = 0;
	while (data->envp[i])
		i++;
	new_env = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (data->envp[i])
	{
		new_env[i] = ft_strdup(data->envp[i]);
		i++;
	}
	ft_freemat(data->envp);
	new_env[i] = ft_strdup(var);
	i++;
	new_env[i] = 0;
	return (new_env);
}

void	ft_export_var(char *arg, t_data *data)
{
	char	*var_name;
	int		j;

	j = 0;
	while (arg[j] && arg[j] != '=')
		j++;
	var_name = ft_substr(arg, 0, j);
	if (ft_env_search(var_name, data->envp) > 0 && \
		ft_env_search(var_name, data->envp) < ft_matlen(data->envp))
	{
		if (ft_strchr(arg, '=') != NULL)
			ft_env_change(data, var_name, arg);
		if (var_name)
			free(var_name);
	}
	else
	{
		if (var_name)
			free(var_name);
		data->envp = ft_env_add(data, arg);
	}
}

int	ft_env(char **args, t_data *data)
{
	int	ret;

	ret = 0;
	if (args[0])
	{
		return (write(2, "nutshell: env: No such file or directory\n", 41), 1);
		ret = 1;
	}
	else
		ft_writemat(data->envp, "\n", 1, 1);
	return (ret);
}
