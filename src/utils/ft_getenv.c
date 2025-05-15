/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:17:40 by everonel          #+#    #+#             */
/*   Updated: 2023/09/14 19:41:19 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_getenv(char *var, char **env)
{
	char	*new;
	int		var_pos;

	var_pos = ft_env_search(var, env);
	new = NULL;
	if (var_pos != -1)
		new = ft_strdup(env[var_pos] + ft_strlen(var) + 1);
	return (new);
}
