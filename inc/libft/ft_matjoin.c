/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 00:11:52 by everonel          #+#    #+#             */
/*   Updated: 2023/09/15 12:13:20 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_new_mat(int len, char **mat1, char **mat2)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = (char **)ft_calloc(sizeof(char *), len + 1);
	while (mat1[i])
	{
		new[i] = ft_strdup(mat1[i]);
		i++;
	}
	while (mat2[j])
	{
		new[i] = ft_strdup(mat2[j]);
		i++;
		j++;
	}
	return (new);
}

char	**ft_matjoin(char **mat1, char **mat2, int free_flag)
{
	char	**new;
	int		len;

	if (!mat1 && !mat2)
		return (NULL);
	else if (!mat1)
		return (mat2);
	else if (!mat2)
		return (mat1);
	len = ft_matlen(mat1) + ft_matlen(mat2);
	new = ft_new_mat(len, mat1, mat2);
	if (free_flag)
		ft_freemat_if(mat1, mat2, free_flag);
	return (new);
}
