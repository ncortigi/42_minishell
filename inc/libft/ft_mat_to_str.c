/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 00:28:29 by everonel          #+#    #+#             */
/*   Updated: 2023/09/12 02:26:08 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_mat_to_str(char **mat)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	while (mat[i])
		len += ft_strlen(mat[i++]);
	str = (char *)ft_calloc(sizeof(char), len + 1);
	i = 0;
	while (mat[i])
	{
		str = ft_strcat(str, mat[i], 1);
		i++;
	}
	return (str);
}
