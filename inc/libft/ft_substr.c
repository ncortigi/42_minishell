/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:26:56 by everonel          #+#    #+#             */
/*   Updated: 2023/09/11 23:24:15 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub_str;
	size_t		i;

	i = 0;
	if (!s)
		return (0);
	sub_str = (char *)ft_calloc(len + 1, sizeof(char));
	while (i < len && start + i <= ft_strlen(s))
	{
		sub_str[i] = s[start + i];
		i++;
	}
	return (sub_str);
}

//int main()
//{
//	printf("%s", ft_substr("lorem ipsum dolor sit amet", 400, 20));
//}
