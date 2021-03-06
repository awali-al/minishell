/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 15:28:53 by awali-al          #+#    #+#             */
/*   Updated: 2020/01/15 14:43:11 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*error_message(char *pwd, int *c)
{
	ft_putstr_fd(pwd, 2);
	ft_putendl_fd(" is not set", 2);
	*c = 0;
	return (NULL);
}

static char	*path_correc(char **line, char **env, int *c)
{
	char		*pwd;

	if (!line[1])
	{
		pwd = value_of(env, "HOME");
		if (!pwd || !pwd[0])
			return (error_message("HOME", c));
		else
			return (ft_strdup(pwd));
	}
	else if (!ft_strcmp(line[1], "-"))
	{
		pwd = value_of(env, "OLDPWD");
		if (!pwd || !pwd[0])
			return (error_message("OLDPWD", c));
		else
			return (ft_strdup(pwd));
	}
	else
		return (ft_strdup(line[1]));
}

static void	check_file(char *tmp, int *c)
{
	struct stat	s;

	*c = 0;
	lstat(tmp, &s);
	if (access(tmp, F_OK))
		ft_putstr_fd("cd: no such file or directory: ", 2);
	else if (!S_ISDIR(s.st_mode))
		ft_putstr_fd("cd: not a directory: ", 2);
	else if (access(tmp, X_OK))
		ft_putstr_fd("cd: permission denied: ", 2);
	ft_putendl_fd(tmp, 2);
}

int			my_cd(char **line, char ***env, int *c)
{
	char	*tmp;
	int		i;

	i = 0;
	while (line[i])
		i++;
	if (i > 2)
	{
		ft_putendl_fd("cd: too many arguments", 2);
		*c = 0;
	}
	else if ((tmp = path_correc(line, *env, c)))
	{
		if (chdir(tmp))
			check_file(tmp, c);
		else
			change_env_path(env, c);
		ft_strdel(&tmp);
	}
	return (0);
}
