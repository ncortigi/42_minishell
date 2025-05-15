/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 00:25:46 by everonel          #+#    #+#             */
/*   Updated: 2023/09/09 15:47:10 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_matdup(char **src, int free_flag)
{
	char	**copy;
	int		i;

	i = 0;
	while (src[i] != 0)
		i++;
	copy = (char **)ft_calloc(sizeof(char *), i + 1);
	i = 0;
	while (src[i])
	{
		copy[i] = ft_strdup(src[i]);
		i++;
	}
	copy[i] = 0;
	if (free_flag == 1)
		ft_freemat(src);
	return (copy);
}
