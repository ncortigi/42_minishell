/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:18:50 by everonel          #+#    #+#             */
/*   Updated: 2022/10/24 16:06:34 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;

	if (!lst || !f)
		return (0);
	new = 0;
	while (lst)
	{
		node = ft_lstnew((*f)(lst -> content));
		if (!node)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&new, node);
		lst = lst -> next;
	}
	return (new);
}
