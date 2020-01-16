/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:11:03 by awali-al          #+#    #+#             */
/*   Updated: 2020/01/15 16:03:53 by awali-al         ###   ########.fr       */
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
	ft_putendl_fd("variable usage : [a-zA-Z_] + [a-zA-Z0-9_]", 2);
	*c = 0;
}

static void	new_env(char ***env, char *varval)
{
	char	**tmp;
	int		n;
	int		i;

	n = 1;
	while ((*env)[n])
		n++;
	tmp = *env;
	(*env) = (char**)malloc((n + 2) * sizeof(char*));
	i = 0;
	while (tmp[i])
	{
		(*env)[i] = ft_strdup(tmp[i]);
		ft_strdel(&tmp[i]);
		i++;
	}
	(*env)[i] = ft_strdup(varval);
	(*env)[++i] = NULL;
	free(tmp);
}

static void	env_change(char ***env, char *varval, char *var, int *c)
{
	int		i;

	i = 0;
	while ((*env)[i] && ft_strstr((*env)[i], var) != (*env)[i])
		i++;
	if ((*env)[i])
	{
		ft_strdel(&((*env)[i]));
		(*env)[i] = ft_strdup(varval);
	}
	else
		new_env(env, varval);
	*c = 1;
}

void		my_set(char **line, char ***env, int *c)
{
	char	*var;
	int		i;

	i = 0;
	while (line[i])
		i++;
	if (i != 2 || !ft_strchr(line[1], '='))
		usage(c);
	else
	{
		i = 0;
		while (variable_char(line[1][i]))
			i++;
		if (!i || ft_isdigit(line[1][0]) || line[1][i] != '=')
			var_corr(c);
		else
		{
			var = ft_strndup(line[1], ft_strchr(line[1], '=') - line[1] + 1);
			env_change(env, line[1], var, c);
			ft_strdel(&var);
		}
	}
}
