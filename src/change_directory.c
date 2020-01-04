/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 14:53:19 by awali-al          #+#    #+#             */
/*   Updated: 2020/01/04 15:00:50 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	bigger_env(char ***env, char *var, int i, int n)
{
	char	**tmp;

	tmp = *env;
	*env = (char**)malloc((n + i + 1) * sizeof(char*));
	n = 0;
	while (tmp[n])
	{
		(*env)[n] = ft_strdup(tmp[n]);
		ft_strdel(&tmp[n]);
		n++;
	}
	free(tmp);
	if (i == 1)
	{
		(*env)[n] = ft_strdup(var);
		n++;
	}
	else
	{
		(*env)[n] = ft_strdup("OLDPWD=");
		(*env)[n + 1] = ft_strdup("PWD=");
		n += 2;
	}
	(*env)[n] = NULL;
}

static void	fixing_env(char ***env)
{
	char	*var;
	int		n;
	int		i;

	i = 2;
	n = 0;
	while ((*env)[n])
	{
		if (ft_strstr((*env)[n], "PWD=") == (*env)[n])
		{
			var = "OLDPWD=";
			i--;
		}
		else if (ft_strstr((*env)[n], "OLDPWD=") == (*env)[n])
		{
			var = "PWD=";
			i--;
		}
		n++;
	}
	if (i)
		bigger_env(env, var, i, n);
}

void		change_env_path(char *path, char ***env, int *c)
{
	int		p;
	int		o;

	fixing_env(env);
	p = 0;
	while (ft_strstr((*env)[p], "PWD=") != (*env)[p])
		p++;
	o = 0;
	while (ft_strstr((*env)[o], "OLDPWD=") != (*env)[o])
		o++;
	ft_strdel(&(*env)[o]);
	(*env)[o] = ft_strjoin("OLD", (*env)[p]);
	ft_strdel(&(*env)[p]);
	(*env)[p] = ft_strjoin("PWD=", path);
	*c = 1;
}
