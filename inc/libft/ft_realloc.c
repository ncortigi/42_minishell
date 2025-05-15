/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 03:38:29 by everonel          #+#    #+#             */
/*   Updated: 2023/09/09 15:44:55 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;
	size_t	i;

	i = 0;
	new_ptr = malloc(size);
	if (!new_ptr)
		return (NULL);
	while (i < size)
	{
		((char *)new_ptr)[i] = ((char *)ptr)[i];
		i++;
	}
	((char *)new_ptr)[i] = 0;
	if (ptr)
		free(ptr);
	return (new_ptr);
}
