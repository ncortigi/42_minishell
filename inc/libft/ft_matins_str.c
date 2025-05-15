/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matins_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 01:12:55 by everonel          #+#    #+#             */
/*   Updated: 2023/09/11 15:11:34 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	**ft_nomat(char *str)
{
	char	**new_mat;

	new_mat = (char **)ft_calloc(2, sizeof(char *));
	new_mat[0] = ft_strdup(str);
	return (new_mat);
}

char	**ft_matins_str(char **mat, char *str, int pos)
{
	char	**new_mat;
	int		i[2];
	int		matlen;

	i[0] = 0;
	i[1] = 0;
	matlen = 0;
	if (!mat)
		return (ft_nomat(str));
	while (mat && mat[matlen])
		matlen++;
	new_mat = (char **)ft_calloc(matlen + 2, sizeof(char *));
	while (i[0] < matlen + 1)
	{
		if (i[0] == pos)
		{
			new_mat[i[0]++] = ft_strdup(str);
			continue ;
		}
		new_mat[i[0]] = ft_strdup(mat[i[1]]);
		i[0]++;
		i[1]++;
	}
	ft_freemat(mat);
	return (new_mat);
}
