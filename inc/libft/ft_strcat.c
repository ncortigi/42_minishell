/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 00:17:52 by everonel          #+#    #+#             */
/*   Updated: 2023/09/09 16:17:03 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char *src, int free_flag)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = (char *)ft_calloc(ft_strlen(dest) + ft_strlen(src) + 1, sizeof(char));
	while (dest[i])
	{
		new[i] = dest[i];
		i++;
	}
	while (src[j])
	{
		new[i] = src[j];
		i++;
		j++;
	}
	ft_free_if(dest, src, free_flag);
	new[i] = '\0';
	return (new);
}
