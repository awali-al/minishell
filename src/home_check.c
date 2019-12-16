/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 16:06:08 by awali-al          #+#    #+#             */
/*   Updated: 2019/12/16 19:44:32 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	find_a_home(char **arg, char *chr)
{
	char			*un;
	int				i;

	i = 0;
	while (ft_isalnum(chr[i + 1]) || chr[i + 1] == '-' || chr[i + 1] == '_'
			|| chr[i + 1] == '.')
		i++;
	un = ft_strsub(chr, 1, i);
	if ((un[0] != '_' && (un[0] > 'z' || un[0] < 'a')) || !user_found(un))
	{
		ft_strdel(arg);
		ft_putstr_fd("zsh: no such user or named directory: ", 2);
		ft_putendl_fd(un, 2);
	}
	else if (!ft_strcmp(un, "root"))
	{
		ft_strdel(arg);
		*arg = ft_strdup("/var/root");
	}
	else
	{
		ft_strdel(arg);
		*arg = ft_strjoin("/Users/", un);
	}
	ft_strdel(&un);
}

static void	home_replacement(char **arg, char *chr, char *home)
{
	char			*tmp;
	char			*str;
	
	if (!chr[1] || chr[1] == '/')
	{
		str = ft_strjoin(home, chr + 1);
		if (*arg != chr)
		{
			tmp = ft_strsub(*arg, 0, chr - *arg);
			free(*arg);
			*arg = ft_strjoin(tmp, str);
			free(tmp);
		}
		else
		{
			free(*arg);
			*arg = ft_strdup(str);
		}
		free(str);
	}
	else
		find_a_home(&arg, chr);
}

static char	*home_filling(char *arg, char **env)
{
	char			*tmp;
	char			*home;

	home = value_of(env, "HOME");
	tmp = arg;
	if (arg[0] == '~')
		home_replacement(&arg, tmp, home);
	while ((tmp = ft_strchr(arg, '~')) && *(tmp - 1) == '=')
		home_replacement(&arg, tmp, home);
	return (arg);
}

char    *home_check(char *str, int *i, char **env)
{
	char			*tmp;
	int				j;

	j = *i;
	while (!space_tab(str[j]) && str[j] != '\'' && str[j] != '\"')
		j++;
	tmp = ft_strsub(str, *i, j - *i);
	*i = j;
	if (ft_strchr(tmp, '~'))
		return (home_filling(tmp, env));
	else
		return (tmp);
}
