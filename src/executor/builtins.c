/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:49:20 by ncortigi          #+#    #+#             */
/*   Updated: 2023/09/14 21:07:59 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_cd(char **args, t_data *data)
{
	int		ret;

	if (!args[0])
		return (write(2, "nutShell: cd: No such file or directory\n", 40), \
				1);
	if (args[1])
		return (write(2, "nutShell: cd: too many arguments\n", 33), 1);
	else
	{
		ret = chdir(args[0]);
		if (ret < 0)
		{
			if (open(args[0], __O_DIRECTORY) < 0 && !access(args[0], F_OK))
				return (write(2, "nutShell: cd: Not a directory\n", 30), 1);
			return (write(2, "nutShell: cd: No such file or directory\n", 40), \
				1);
		}
		else
			ft_pwd_replace(data, ft_env_search("PWD", data->envp));
	}
	return (ret);
}

// funzione per eseguire il comando pwd
int	ft_pwd(void)
{
	char	path[128];

	getcwd(path, 128);
	printf ("%s\n", path);
	return (0);
}

// funzione per eseguire il comando echo
int	ft_echo(char **args)
{
	int	i;
	int	option;

	option = 1;
	i = 0;
	if (args[i] && (!ft_strncmp(args[i], "-n ", 3) || \
		!ft_strncmp(args[i], "-n", 3)))
	{
		option = -1;
		i++;
	}
	while (args[i])
	{
		printf("%s", args[i]);
		i++;
	}
	if (option > 0)
		printf("\n");
	return (0);
}

// funzione per eseguire il comando unset
int	ft_unset(char **args, t_data *data)
{
	int	ret;

	ret = 0;
	while (*args)
	{
		ret = ft_env_search(*args, data->envp);
		if (ret >= 0 && ret < ft_matlen(data->envp))
			data->envp = ft_env_remove(*args, data);
		args++;
	}
	return (0);
}
