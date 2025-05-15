/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:06:08 by ncortigi          #+#    #+#             */
/*   Updated: 2023/09/14 13:06:52 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_data	*ft_init_data(char **envp)
{
	t_data	*data;

	data = (t_data *)ft_calloc(sizeof(t_data), 1);
	data->envp = ft_matdup(envp, 0);
	data->export = NULL;
	data->original_std_fd[0] = dup(0);
	data->original_std_fd[1] = dup(1);
	g_status = 0;
	return (data);
}

//Restituisce una stringa col prompt da stampare a schermo
char	*ft_return_prompt(void)
{
	char	*user;

	user = getenv("USER");
	return (ft_strjoin(user, "@nutShell ", 0));
}

//Se detecta il ctrl-c restituisce il prompt dopo uno "\n"
void	ft_siginthandler(int sign)
{
	if (sign == SIGINT)
	{
		g_status = 130;
		waitpid(-1, NULL, WUNTRACED);
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}
