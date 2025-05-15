/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrotone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:36:19 by everonel          #+#    #+#             */
/*   Updated: 2023/09/09 16:14:50 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_matrotone(char ***matrix)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (*matrix)[i];
	while ((*matrix)[i + 1])
	{
		(*matrix)[i] = (*matrix)[i + 1];
		i++;
	}
	(*matrix)[i] = tmp;
	free(tmp);
}
