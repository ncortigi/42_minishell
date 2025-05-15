/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:08:38 by everonel          #+#    #+#             */
/*   Updated: 2023/08/28 17:47:04 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2, int free_flag)
{
	char	*new;
	size_t	tot_len;
	size_t	i;
	size_t	j;

	tot_len = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)ft_calloc(tot_len + 1, sizeof(char));
	if (!new)
		return (0);
	i = 0;
	while (i < (tot_len - ft_strlen(s2)) && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (i < tot_len && s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	ft_free_if((char *)s1, (char *)s2, free_flag);
	return (new);
}
//#include <stdio.h>
//int main ()
//{
//	printf("%s", ft_strjoin("lorem", "ipsum"));
//}
