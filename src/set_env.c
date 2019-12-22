/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:11:03 by awali-al          #+#    #+#             */
/*   Updated: 2019/12/22 02:59:42 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	usage(int *c)
{
	ft_putendl_fd("usage: setenv variable=value", 2);
	*c = 0;
}

static void	var_corr(int *c)
{
	ft_putendl_fd("variable usage : [a-z_] + [a-z0-9_]", 2);
	*c = 0;
}

static void	new_env(char ***env, char *var, char *val)
{
	char	**tmp;
	int		n;
	int		i;
	
	n = 0;
	while (*env[n])
		n++;
	tmp = *env;
	*env = (char**)malloc((n + 1) * sizeof(char*));
	*env[n] = NULL;
	*env[n - 1] = ft_strjoin(var, val);
	i = 0;
	while (tmp[i])
	{
		*env[i] = ft_strdup(tmp[i]);
		ft_strdel(&tmp[i]);
		i++;
	}
	free(tmp);
}

static void	env_change(char ***env, char *var, char *val, int *c)
{
	char	*tmp;
	int		i;
	
	i = 0;
	while (ft_strstr(*env[i], var) != *env[i])
		i++;
	tmp = ft_strjoin("=", val);
	if (*env[i])
	{
		ft_strdel(&(*env[i]));
		*env[i] = ft_strjoin(var, tmp);
	}
	else
		new_env(env, var, tmp);
	ft_strdel(&tmp);
	*c = 1;
}

void		my_set(char **line, char ***env, int *c)
{
	char	*var;
	char	*val;
	int		i;

	i = 0;
	while (line[i])
		i++;
	if (i != 2)
		usage(c);
	else
	{
		i = 0;
		while (variable_char(line[1][i]))
			i++;
		if (!i || ft_isalpha(line[1][0]) || line[1][i] != '=')
			var_corr(c);
		else
		{
			var = ft_strndup(line[1], i);
			val = line[1] + i + 1;
			env_change(env, var, val, c);
			ft_strdel(&var);
		}
	}
}
