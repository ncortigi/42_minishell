/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_builtins_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:18:29 by ncortigi          #+#    #+#             */
/*   Updated: 2023/09/09 15:13:49 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_return_format(char *line)
{
	char	*gg;
	char	*ret;

	gg = NULL;
	ret = NULL;
	if (ft_strchr(line, '=') != NULL)
	{
		gg = ft_strjoin("declare -x ", line, 2);
		ret = ft_strjoin(gg, "\"", 0);
		free(gg);
		return (ret);
	}
	return (ft_strjoin("declare -x ", line, 2));
}

// int	ft_write(t_red **redir, t_cmd *cmd)
// {
// 	t_red	*head;
// 	int		fd;

// 	fd = -1;
// 	(void) cmd;
// 	head = *redir;
// 	while (head)
// 	{
// 		if (head->token == 1) {
// 			fd = open(head->out_fd, O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 		if (fd == -1)
// 				return (perror("Error opening file"), 1);
// 		}
// 		else if (head->token == 2){
// 			fd = open(head->out_fd, O_WRONLY | O_CREAT | O_APPEND, 0644);
// 			if (fd == -1)
// 				return (perror("Error opening file"), 1);
// 		}
// 		else
// 		{
// 			close (fd);
// 			continue ;
// 		}
// 		dup2(fd, 1);
// 		close(fd);
// 		head = head->next;
// 	}
// 	return (0);
// }
