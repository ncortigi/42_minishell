/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_rem_chr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 00:38:21 by everonel          #+#    #+#             */
/*   Updated: 2023/09/09 15:58:01 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_rem_chr(char *str, char c, int free_flag)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = (char *)ft_calloc(sizeof(char), ft_strlen(str));
	while (str[i])
	{
		if (str[i] != c)
		{
			new[j] = str[i];
			j++;
		}
		i++;
	}
	ft_free_if(str, NULL, free_flag);
	return (new);
}
