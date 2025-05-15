/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:36:36 by everonel          #+#    #+#             */
/*   Updated: 2022/10/16 16:21:42 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = ft_strlen(little);
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (i <= len-- && *big)
	{
		if (!(ft_strncmp((char *)big, (char *)little, i)))
		{
			return ((char *)big);
		}
		big++;
	}
	return (0);
}

//int main()
//{
//	printf("%s\n", ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15));
//}
