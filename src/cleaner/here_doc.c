/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:49:29 by ncortigi          #+#    #+#             */
/*   Updated: 2023/09/14 14:47:07 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

//Teoricamente questo viene usato solo con cat e echo, considerare l'ipotesi di
//far stampare direttamente a questa funzione cio' che viene scritto dall'utente
char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2, 0);
	free(s1);
	if (ft_strncmp(s2, "\n", 1))
		free(s2);
	return (str);
}

//Questa funzione restituisce una stringa con all'interno cio' che e' 
//stato scritto senza il limit
char	*ft_here_doc(char *limit)
{
	char	*input;
	char	*buff;
	int		fd;

	buff = ft_strdup("");
	input = ft_strdup("");
	while (1)
	{
		if (ft_strlen(limit) == (ft_strlen(buff) - 1) && \
			!ft_strncmp(buff, limit, ft_strlen(limit)))
			break ;
		input = ft_strjoin_free(input, buff);
		buff = readline("> ");
		buff = ft_strjoin_free(buff, "\n");
	}
	free(buff);
	fd = open(".heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (!fd)
		return (NULL);
	write(fd, input, ft_strlen(input));
	close(fd);
	return (".heredoc");
}
