/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:04:27 by everonel          #+#    #+#             */
/*   Updated: 2022/10/10 14:07:07 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	if (nmemb * size < nmemb || nmemb * size < size)
		return (malloc(0));
	arr = (void *)malloc(nmemb * size);
	if (!arr)
		return (0);
	ft_bzero(arr, nmemb * size);
	return (arr);
}
