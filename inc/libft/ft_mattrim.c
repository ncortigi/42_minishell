/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mattrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 03:02:30 by everonel          #+#    #+#             */
/*   Updated: 2023/09/09 15:38:06 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_mattrim(char **mat, char *str)
{
	char	**new_mat;
	int		i;
	int		j;

	i = 0;
	j = ft_matlen(mat) - 1;
	while (mat[i] && ft_strcmp(mat[i], str))
		i++;
	while (mat[j] && ft_strcmp(mat[j], str))
		j--;
	new_mat = (char **)ft_calloc(sizeof(char *), ft_matlen(mat) - (j - i) + 1);
	while (i < j)
	{
		*new_mat = ft_strdup(mat[i]);
		i++;
		*new_mat += 1;
	}
	*new_mat = 0;
	ft_freemat(mat);
	return (new_mat);
}
