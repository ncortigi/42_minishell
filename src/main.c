/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:33:46 by ncortigi          #+#    #+#             */
/*   Updated: 2023/07/24 19:33:46 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	g_status = 0;
//<Makefile cat| echo "$PWD 'hola'" ~/src | 'tr' -d / >outfile

// main function
int	main(int ac, char **av, char **envp)
{
	t_data	*data;
	int		status;

	(void)ac;
	(void)av;
	data = ft_init_data(envp);
	ft_run_shell(data);
	status = g_status;
	ft_freedata(data);
	return (status);
}

static void	ft_run_exe(t_data *data, t_cmd **cmd)
{
	int		old_in;
	int		n_piped;
	t_cmd	*head;

	head = *cmd;
	data->cmd_ast = cmd;
	old_in = dup(data->original_std_fd[0]);
	n_piped = 0;
	while (head)
	{
		if (ft_strcmp(head->args[0], ".heredoc"))
			g_status = ft_executor(head, data, old_in, n_piped);
		else
			g_status = 0;
		if (g_status)
			break ;
		head = head->next;
		n_piped++;
	}
	close(old_in);
	ft_reset_cmdline(data);
	ft_freecmdast(cmd);
}

static int	ft_loop(char *input, t_cmd ***cmd, t_data *data)
{
	char	*prompt;

	while (1)
	{
		signal(SIGINT, ft_siginthandler);
		signal(SIGQUIT, SIG_IGN);
		prompt = ft_return_prompt();
		input = readline(prompt);
		free(prompt);
		if (!input)
			return (0);
		if (input[0] == '\n' || input[0] == '\0')
			continue ;
		add_history(input);
		*cmd = ft_parse_input(input, data);
		if (!*cmd) 
			continue ;
		if (!ft_strcmp((**cmd)->args[0], "exit") && !ft_error_exit(*cmd, 2))
		{
			if (!ft_exit_or_continue(*cmd))
				continue ;
			return (1);
		}
		ft_run_exe(data, *cmd);
	}
}

void	ft_run_shell(t_data *data)
{
	char		*input;
	t_cmd		**cmd;
	int			i;

	input = NULL;
	cmd = NULL;
	i = ft_loop(input, &cmd, data);
	if (i)
		ft_freecmdast(cmd);
	else
		write(1, "exit\n", 5);
}

// function to clean the input
t_cmd	**ft_parse_input(char *line, t_data *data)
{
	char		**cmd_mat;
	t_cmd		**cmd;

	(void)data;
	cmd = NULL;
	cmd_mat = ft_lex_input(line, 0);
	if (!cmd_mat)
		return (cmd);
	g_status = ft_expacker(cmd_mat, data);
	free (line);
	if (!g_status && cmd_mat)
		cmd = ft_parser(cmd_mat, 0, 0, data);
	ft_freemat(cmd_mat);
	return (cmd);
}
