/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:11:03 by awali-al          #+#    #+#             */
/*   Updated: 2019/11/28 15:29:14 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	usage(int *c)
{
	ft_putendl_fd("usage: setenv VARIABLE=value", 2);
	*c = 0;
}

static void	set_env(char ***env, char **arr)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strjoin(arr[0], "=");
	while (*env[i] != ft_strstr(*env[i], tmp))
		i++;
	if (*env[i])
	{
		ft_strdel(&(*env[i]));
		*env[i] = ft_strjoin(tmp, arr[1]);
	}
	else
	{
		
	}
	ft_strdel(&tmp);
}

void		my_set(char **line, char ***env, int *c)
{
	/*char	**arr;
	char	*rest;

	if (line[7])
	{
		rest = line + 7;
		if (ft_strchr(rest, ' ') || ft_strchr(ft_strchr(rest, '=') + 1, '='))
			usage(c);
		else
		{
			arr = ft_strsplit(rest, '=');
			set_env(env, arr);
			free_2d(arr);
			*c = 1;
		}
	}
	else
		usage(c);*/
}
