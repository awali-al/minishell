/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:22:04 by awali-al          #+#    #+#             */
/*   Updated: 2019/11/29 18:00:16 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*edited_arg(char *arg, char *dol, char **env)
{
	char	*tmp1;
	char	*tmp2;
	int		n;

	n = 0;
	while (dol[n + 1] == '_' || ft_isalnum(dol[n + 1]))
		n++;
	
}

static char	*potential_value(char *arg, char **env)
{
	char	*val;
	char	*tmp;
	
	if ((tmp = ft_strchr(arg[0], '$') + 1))
	{
		if ((val = edited_arg(arg, tmp, env)))
			return (ft_strdup(val));
		else
			return (NULL);
	}
	else
		return (ft_strdup(arg));
}

void		my_echo(char **line, char **env, int *c)
{
	char	*tmp;
	int		i;
	int		n;

	n = 0;
	if (!ft_strcmp(line[i], "-n"))
		n = 1;
	i = 1 + n;
	while (line[i])
	{
		tmp = potential_value(line[i], env);
		if (tmp)
		{
			ft_putstr(tmp);
			if (line[++i])
				write(1, " ", 1);
			else if (!n)
				write(1, "\n", 1);
			ft_strdel(&tmp);
		}
	}
}
