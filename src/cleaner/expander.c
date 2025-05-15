/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:52:12 by ncortigi          #+#    #+#             */
/*   Updated: 2023/09/14 19:30:25 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_take_var(char *mat, t_data *data, int *i)
{
	char	*var;
	char	*str;

	while (ft_isalnum(mat[*i]) || mat[*i] == '_')
		(*i)++;
	str = ft_substr(mat, 0, *i);
	var = ft_getenv(str, data->envp);
	free(str);
	return (var);
}

// function to expand the $var
char	*ft_expander(char **mat, t_data *data, int s)
{
	int		i;
	char	*var;
	char	*sub;

	i = 0;
	while (mat[s])
	{
		if (mat[s][0] == '?')
		{
			var = ft_itoa(g_status); 
			i++;
		}
		else
			var = ft_take_var(mat[s], data, &i);
		if (!var)
			var = ft_strdup("");
		sub = ft_substr(mat[s], i, ft_strlen(mat[s]) - i);
		free(mat[s]);
		mat[s] = ft_strjoin(var, sub, 3);
		i = 0;
		s++;
	}
	return (ft_mat_to_str(mat));
}
