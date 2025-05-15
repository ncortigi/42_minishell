/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:36:11 by everonel          #+#    #+#             */
/*   Updated: 2022/10/16 16:19:49 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t		dst_len;
	size_t		i;

	dst_len = ft_strlen(dst);
	i = 0;
	while (src[i] != '\0' && i + dst_len + 1 < size)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len < size && size > 0)
	{
		dst[i + dst_len] = '\0';
		return (dst_len + ft_strlen(src));
	}
	return (ft_strlen(src) + size);
}
