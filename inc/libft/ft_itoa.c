/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:31:39 by everonel          #+#    #+#             */
/*   Updated: 2023/09/09 15:36:35 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fill_new(char *new, long int n, size_t len);
size_t	get_len(int n);

char	*ft_itoa(int n)
{
	char		*new;
	size_t		len;
	long int	num;

	num = n;
	len = get_len(n);
	if (n < 0)
	{
		num *= -1;
		len++;
	}
	new = (char *)malloc(sizeof(char) * len + 1);
	if (!new)
		return (0);
	new[len] = 0;
	fill_new(new, num, len);
	if (n < 0)
		new[0] = '-';
	return (new);
}

size_t	get_len(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	if (i == 0)
		i = 1;
	return (i);
}

char	*fill_new(char *new, long int n, size_t len)
{
	while (len--)
	{
		new[len] = (n % 10) + 48;
		n /= 10;
	}
	return (new);
}
