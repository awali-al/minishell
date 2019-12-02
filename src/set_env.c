/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:11:03 by awali-al          #+#    #+#             */
/*   Updated: 2019/12/02 22:08:45 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	usage(int *c)
{
	ft_putendl_fd("usage: setenv variable value", 2);
	*c = 0;
}

static char	**new_env(char **env, int i, char **line, char *tmp)
{
	char	**ret;

	ret = (char**)malloc((i + 2) * sizeof(char*));
	ret[i + 1] = NULL;
	ret[i] = ft_strjoin(line[1], tmp);
	i = 0;
	while(env[i])
	{
		ret[i] = ft_strdup(env[i]);
		i++;
	}
	return (ret);
}

static void	ch_env(char ***env, int e, char **line, int *c)
{
	char	**tmp_env;
	char	*tmp;
	int		i;
	
	tmp = ft_strjoin("=", line[2]);
	if (e >= 0)
	{
		ft_strdel(&(*env[e]));
		*env[e] = ft_strjoin(line[1], tmp);
	}
	else
	{
		i = 0;
		while (env[i])
			i++;
		tmp_env = *env;
		*env = new_env(tmp_env, i, line, tmp); 
		free_2d(tmp_env);
	}
	ft_strdel(&tmp);
	*c = 1;
}

void		my_set(char **line, char ***env, int *c)
{
	int		i;
	int		e;

	i = 0;
	e = -1;
	while (line[i])
		i++;
	if (i == 3)
	{
		i = 0;
		while (*env[i] && e < 0)
		{
			if (ft_strstr(*env[i], line[1]) == *env[i])
				e = i;
			i++;
		}
		ch_env(env, e, line, c);
	}
	else
		usage(c);
}
