/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 23:42:55 by aminewalial       #+#    #+#             */
/*   Updated: 2019/12/26 20:57:24 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	usage(int *c)
{
	ft_putendl_fd("usage: unsetenv variable", 2);
	*c = 0;
}

static void	var_error(char **line, int *c)
{
	ft_putstr_fd("unsetenv: unfound variable: ", 2);
	ft_putendl_fd(line[1], 2);
	*c = 0;
}

static void	new_env(char ***env, int e, int *c)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	tmp = *env;
	while (tmp[i])
	{
		i++;
	}
	*env = (char**)malloc(i * sizeof(char*));
	(*env)[i - 1] = NULL;
	i = 0;
	j = 0;
	while (tmp[i])
	{
		if (i != e)
		{
			(*env)[j] = ft_strdup(tmp[i]);
			j++;
		}
		free(tmp[i]);
		i++;
	}
	free(tmp);
	*c = 1;
}

void		my_unset(char **line, char ***env, int *c)
{
	int		i;
	int		e;

	i = 0;
	e = -1;
	while (line[i])
		i++;
	if (i == 2)
	{
		i = 0;
		while ((*env)[i] && e < 0)
		{
			if (ft_strstr((*env)[i], line[1]) == (*env)[i])
				e = i;
			i++;
		}
		if (e >= 0)
			new_env(env, e, c);
		else
			var_error(line, c);
	}
	else
		usage(c);
}
