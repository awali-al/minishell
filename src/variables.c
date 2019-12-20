/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 19:45:19 by awali-al          #+#    #+#             */
/*   Updated: 2019/12/20 00:55:19 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	fill_in(char **arg, char *dol, char *val, int i)
{
	char	*tmp;
	char	*str;
	char	*prv;

	tmp = *arg;
	str = ft_strjoin(val, dol + i + 1);
	if (tmp == dol)
		*arg = ft_strdup(str);
	else
	{
		prv = ft_strndup(tmp, dol - tmp);
		*arg = ft_strjoin(prv, str);
		ft_strdel(&prv);
	}
	ft_strdel(&str);
	ft_strdel(&tmp);
}

void		var(char **arg, char **env)
{
	char	*val;
	char	*dol;
	int		c;
	int		i;

	c = 1;
	while ((dol = ft_strchr(*arg, '$')) && c)
	{
		if (!dol[1])
			c = 0;
		else
		{
			i = 0;
			while (variable_char(dol[i + 1]))
				i++;
			val = ft_strsub(val, 1, i);
			fill_in(arg, dol, val, i);
			ft_strdel(&val);
		}
	}
}