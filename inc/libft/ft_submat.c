/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_submat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 00:15:34 by everonel          #+#    #+#             */
/*   Updated: 2023/09/09 16:06:31 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_submat(char **mat, int start, int end, int free_flag)
{
	int		len;
	char	**new;

	len = 0;
	while (len < end - start)
		len++;
	new = (char **)ft_calloc(sizeof(char *), len + 1);
	len = 0;
	while (start < end)
	{
		new[len] = ft_strdup(mat[start]);
		len++;
		start++;
	}
	if (free_flag == 1)
		ft_freemat(mat);
	return (new);
}
