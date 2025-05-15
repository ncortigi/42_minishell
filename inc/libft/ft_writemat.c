/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writemat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 00:35:42 by everonel          #+#    #+#             */
/*   Updated: 2023/09/09 16:13:41 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_writemat(char **mat, char *sep, int fd, int env)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		if (env && ft_strchr(mat[i], '=') == NULL)
			i++;
		else
		{
			write(fd, mat[i], ft_strlen(mat[i]));
			write(fd, sep, ft_strlen(sep));
			i++;
		}
	}
}
