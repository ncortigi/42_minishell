/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:54:05 by ncortigi          #+#    #+#             */
/*   Updated: 2023/09/14 15:07:59 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// extern int g_status;

// funzione per salvare la vecchia pwd e aggiornare la pwd
void	ft_pwd_replace(t_data *data, int line)
{
	char	*old;
	char	*pwd;
	char	path[128];
	char	*new_line;
	char	**value;

	old = ft_strdup(data->envp[line]);
	pwd = ft_strjoin("PWD=", getcwd(path, 128), 0);
	ft_env_change(data, "PWD", pwd);
	free(pwd);
	value = ft_split(old, '=');
	free(old);
	new_line = ft_strjoin("OLDPWD=", value[1], 0);
	ft_env_change(data, "OLDPWD", new_line);
	free(new_line);
	ft_freemat(value);
}

int	ft_exit_or_continue(t_cmd **cmd)
{
	if (ft_error_exit(cmd, 1))
	{
		g_status = ft_error_exit(cmd, 0);
		return (0);
	}
	g_status = ft_exit((*cmd)->args);
	return (1);
}

int	ft_exit_pipe(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->next)
	{
		cmd = cmd->next;
		i++;
	}
	if (!i)
		return (0);
	return (1);
}

int	ft_error_exit(t_cmd **cmd, int control)
{
	int	i;

	i = 0;
	if (!control)
	{
		write(1, "exit\n", 5);
		write(2, "nutshell: exit: too many arguments\n", 35);
		ft_freecmdast(cmd);
		return (1);
	}
	else if (control == 1)
	{
		while ((*cmd)->args[i])
			i++;
		if (i == 3 && (*cmd)->args[1] && \
			ft_strcmp((*cmd)->args[1], "-") && \
			ft_strcmp((*cmd)->args[1], "+"))
			return (1);
		return (0);
	}
	else
		return (ft_exit_pipe(*cmd));
}
