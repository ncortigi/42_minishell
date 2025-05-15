/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matdelstr_idx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 03:15:48 by everonel          #+#    #+#             */
/*   Updated: 2023/09/09 18:21:04 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_new(char **mat, int pos, char *str)
{
	char	**new_mat;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_mat = (char **)malloc(sizeof(char *) * ft_matlen(mat));
	while (mat[i])
	{
		if (i == pos && ft_strncmp(mat[i], str, ft_strlen(str)) == 0)
		{
			free(mat[i]);
			i++;
		}
		else
		{
			new_mat[j] = ft_strdup(mat[i]);
			j++;
			i++;
		}
	}
	new_mat[j] = NULL;
	free(mat);
	return (new_mat);
}

char	**ft_matdelstr_idx(char **mat, char *str, int pos)
{
	char	**new_mat;

	if (ft_matlen(mat) == 0)
		return (mat);
	if (ft_matlen(mat) == 1)
	{
		if (ft_strncmp(mat[0], str, ft_strlen(str)) == 0)
		{
			free(mat[0]);
			free(mat);
			return (NULL);
		}
		else
			return (mat);
	}
	new_mat = ft_new(mat, pos, str);
	return (new_mat);
}
