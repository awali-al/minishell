/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminewalialami <aminewalialami@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:39:41 by awali-al          #+#    #+#             */
/*   Updated: 2019/12/01 17:11:18 by aminewalial      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*fitting(char *value, char *arg, char *doll, int l)
{
	char	*tmp;
	char	*prv;
	char	*ret;

	if (value)
		tmp = ft_strjoin(value, doll + l);
	else
		tmp = ft_strdup(doll + l);
	prv = ft_strndup(arg, doll - arg - 1);
	if (prv)
		ret = ft_strjoin(prv, tmp);
	else
		ret = ft_strdup(tmp);
	ft_strdel(&tmp);
	prv ? ft_strdel(&prv) : 0;
	return (ret);
}

static void valuable(char **arg, char **env, char *doll)
{
	char	*tmp;
	char	*var;
	int		i;

	tmp = *arg;
	i = 0;
	while (ft_isalnum(doll[i]) || doll[i] == '_')
		i++;
	var = ft_strndup(doll, i);
	*arg = fitting(value_of(env, var), tmp, doll, i);
	ft_strdel(&var);
	ft_strdel(&tmp);
}

static void	homify(char **line, char **env)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strjoin(value_of(env, "HOME"), tmp + 1);
	ft_strdel(&tmp);
}

void		variables(char ***line, char **env)
{
	char	*doll;
	int		i;

	i = 0;
	while (*line[i])
	{
		if (*line[i][0] == '~')
			homify(&(*line[i]), env);
		while ((doll = ft_strchr(*line[i], '$') + 1))
			valuable(&(*line[i]), env, doll);
		if (!line[i])
			line[i] = ft_strnew(1);
	}
}