/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 20:01:38 by everonel          #+#    #+#             */
/*   Updated: 2023/09/15 00:25:56 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// function to collect the args of a t_cmd
char	**ft_getcmd_args(char **tmp, int *pos)
{
	char	**args;
	int		i;

	i = 0;
	while (tmp[i] && tmp[i][0] != '>' && tmp[i][0] != '<')
		i++;
	args = (char **)ft_calloc(sizeof(char *), i + 1);
	i = 0;
	while (tmp[i] && tmp[i][0] != '>' && tmp[i][0] != '<')
	{
		args[i] = ft_strdup(tmp[i]);
		i++;
	}
	*pos += i;
	return (args);
}

char	*ft_discover_path(char *str)
{
	if (access(str, F_OK) == 0)
		return (ft_strdup(str));
	else
		return (NULL);
}

// function to get a command path
char	*ft_get_cmd_path(char *cmd, t_data *data)
{
	char	*path;
	char	*tmp;
	char	**path_lst;
	int		i;

	i = 0;
	path = NULL;
	tmp = ft_getenv("PATH", data->envp);
	if (!tmp)
		return (ft_strdup(cmd));
	path_lst = ft_split(tmp, ':');
	free(tmp);
	while (path_lst[i])
	{
		path = ft_strjoin(ft_strjoin(path_lst[i], "/", 0), cmd, 1);
		if (access(path, F_OK) == 0)
			break ;
		free (path);
		path = NULL;
		i++;
	}
	if (!path)
		path = ft_strdup(cmd);
	ft_freemat(path_lst);
	return (path);
}

// function to obtain the t_cmd list size
int	ft_cmdsize(t_cmd **cmd)
{
	t_cmd	*head;
	int		i;

	i = 0;
	head = *cmd;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}
