/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:27:24 by ncortigi          #+#    #+#             */
/*   Updated: 2023/09/14 13:13:05 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	ft_calculate_exit_status(char **args)
{
	int		nbr;
	char	*str;

	if (args[2])
		str = ft_strjoin(args[1], args[2], 0);
	else
		str = ft_strdup(args[1]);
	nbr = ft_atoi(str);
	free(str);
	return (nbr);
}

int	ft_exit(char **args)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	write(1, "exit\n", 5);
	if (!args[1])
		return (0);
	if ((args[1][i] == '-' || args[1][i] == '+') && args[1][i + 1] != '\0')
		i++;
	if (!ft_strcmp(args[1], "-") || !ft_strcmp(args[1], "+"))
		j++;
	while (args[j][i])
	{
		if (args[j][i] < 48 || args[j][i] > 57)
			return (write(2, "nutshell: exit: numeric argument required\n", \
				42), 2);
		i++;
	}
	return (ft_calculate_exit_status(args));
}

int	ft_check_exportvar(char *arg)
{
	int	i;

	i = 0;
	if (!ft_strncmp(arg, "=", 1))
		return (write(2, "nutshell: export: not a valid identifier\n", 41), 1);
	if (arg[i] >= 48 && arg[i] <= 57)
		return (write(2, "nutshell: export: not a valid identifier\n", 41), 1);
	while (arg[i] && arg[i] != '=')
	{
		if (arg[i] < 48 || (arg[i] > 57 && arg[i] < 61) || \
			(arg[i] > 61 && arg[i] < 65) || \
			(arg[i] > 90 && arg[i] < 95) || \
			(arg[i] > 95 && arg[i] < 97) || arg[i] > 122)
			return (write(2, "nutshell: export: not a valid identifier\n", \
				41), 1);
		i++;
	}
	return (0);
}

// funzione per eseguire il comando export
int	ft_export(char **args, t_data *data)
{
	int	ret;

	ret = 0;
	if (!*args)
	{
		if (data->export)
			ft_freemat(data->export);
		data->export = ft_make_export(data);
		ft_writemat(data->export, "\n", 1, 0);
		return (0);
	}
	else
	{
		while (*args)
		{
			if (!ft_check_exportvar(*args))
				ft_export_var(*args, data);
			else
				ret = 1;
			args++;
		}
	}
	return (ret);
}
