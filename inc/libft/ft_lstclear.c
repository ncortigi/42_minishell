/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:13:36 by everonel          #+#    #+#             */
/*   Updated: 2022/10/22 16:17:02 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*new;

	if (!del)
		return ;
	while (*lst)
	{
		del((*lst)-> content);
		new = *lst;
		*lst = new -> next;
		free(new);
	}
	*lst = NULL;
}
