/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:06:14 by everonel          #+#    #+#             */
/*   Updated: 2023/09/09 16:13:16 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strins(char *s1, char *s2, int idx, int free_flag)
{
	char	*new;
	int		i;
	int		s2_len;

	i = 0;
	s2_len = ft_strlen(s2);
	new = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	while (i < idx)
	{
		new[i] = s1[i];
		i++;
	}
	while (i < idx + s2_len)
	{
		new[i] = s2[i - idx];
		i++;
	}
	while (s1[i - s2_len])
	{
		new[i] = s1[i - s2_len];
		i++;
	}
	new[i] = '\0';
	ft_free_if(s1, s2, free_flag);
	return (new);
}
