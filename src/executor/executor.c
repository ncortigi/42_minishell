/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 01:50:20 by everonel          #+#    #+#             */
/*   Updated: 2023/09/15 00:23:53 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_who_exe(t_cmd *cmd, t_data *data)
{
	if (ft_is_builtin(cmd->args[0]))
		return (ft_exe_external(cmd, data));
	else if (!ft_is_builtin(cmd->args[0]))
		return (ft_exe_builtin(cmd, data));
	else
		return (0);
}

int	ft_executor(t_cmd *cmd, t_data *data, int old_in, int n_piped)
{
	int	pipe_fds[2];

	if (cmd->next) 
	{
		if (pipe(pipe_fds) == -1)
			return (perror("pipe Error"), 1);
		dup2(pipe_fds[1], 1);
		close(pipe_fds[1]);
	}
	if (cmd->next || n_piped > 0)
	{
		dup2(old_in, 0);
		close(old_in);
		if (cmd->next)
		{
			old_in = dup(pipe_fds[0]);
			close(pipe_fds[0]);
		}
	}
	if (cmd->next == NULL)
		dup2(data->original_std_fd[1], 1);
	return (ft_who_exe(cmd, data));
}

int	ft_exe_external(t_cmd *cmd, t_data *data)
{
	pid_t	pid;
	int		wstatus;

	pid = fork();
	if (pid < 0)
		return (perror("fork error"), 1);
	if (pid == 0)
	{
		signal(SIGINT, ft_siginthandler);
		signal(SIGQUIT, SIG_IGN);
		if (cmd->redir)
			if (ft_redir(cmd->redir, data))
				return (1);
		execve(cmd->path, cmd->args, data->envp);
		ft_print_error(0);
		ft_freecmdast(data->cmd_ast);
		ft_freedata(data);
		exit(127);
	}
	waitpid(pid, &wstatus, 0);
	if (WIFEXITED(wstatus))
		return (WEXITSTATUS(wstatus));
	return (0);
}

// function to execute the builtin command
int	ft_exe_builtin(t_cmd *cmd, t_data *data)
{
	if (cmd->redir)
		if (ft_redir(cmd->redir, data))
			return (1);
	if (!ft_strcmp(cmd->args[0], "pwd"))
		return (ft_pwd());
	else if (!ft_strcmp(cmd->args[0], "echo"))
		return (ft_echo((cmd->args + 1)));
	else if (!ft_strcmp(cmd->args[0], "cd"))
		return (ft_cd((cmd->args + 1), data));
	else if (!ft_strcmp(cmd->args[0], "export"))
		return (ft_export((cmd->args + 1), data));
	else if (!ft_strcmp(cmd->args[0], "unset"))
		return (ft_unset((cmd->args + 1), data));
	else if (!ft_strcmp(cmd->args[0], "env"))
		return (ft_env((cmd->args + 1), data));
	return (0);
}

int	ft_is_builtin(char *cmd)
{
	if (!ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, "cd") || \
		!ft_strcmp(cmd, "pwd") || !ft_strcmp(cmd, "export") || \
		!ft_strcmp(cmd, "unset") || !ft_strcmp(cmd, "env") || \
		!ft_strcmp(cmd, "exit"))
		return (0);
	return (1);
}
