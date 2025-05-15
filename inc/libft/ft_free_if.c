/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_if.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 00:41:14 by everonel          #+#    #+#             */
/*   Updated: 2023/09/09 16:05:46 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_if(char *dest, char *src, int free_flag)
{
	if (free_flag == 1 && dest)
		free(dest);
	if (free_flag == 2 && src)
		free(src);
	if (free_flag == 3)
	{
		if (dest)
			free(dest);
		if (src)
			free(src);
	}
	else
		return ;
}
