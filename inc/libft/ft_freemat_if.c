/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freemat_if.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:38:13 by everonel          #+#    #+#             */
/*   Updated: 2023/09/09 16:14:08 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freemat_if(char **mat1, char **mat2, int free_flag)
{
	if (free_flag == 1)
		ft_freemat(mat1);
	else if (free_flag == 2)
		ft_freemat(mat2);
	else if (free_flag == 3)
	{
		ft_freemat(mat1);
		ft_freemat(mat2);
	}
}
