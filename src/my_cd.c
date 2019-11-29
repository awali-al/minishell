/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 15:28:53 by awali-al          #+#    #+#             */
/*   Updated: 2019/11/28 20:33:41 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*path_correc(char *path, char **env)
{
	char		*var;
	
	if (!path)
		return (ft_strdup(value_of(env, "HOME")));
	else if (ft_strcmp(*path, "-"))
		return (ft_strdup(value_of(env, "OLDPWD")));
	else if ((var = ft_strchr(path[0], '$')))
	{
		//I still need to figure out how to replace variables even if they were in the middle of the agrument w%assni n9addha fecho 7tta hiya
		return (ft_strdup(value_of(path, env)));
	}
}

static void	check_file(char *rest, int *c)
{
	struct stat	s;
	
	*c = 0;
	lstat(rest, &s);
	if (access(rest, F_OK))
		ft_putstr_fd("cd: no such file or directory: ", 2);
	else if (!S_ISDIR(s.st_mode))
		ft_putstr_fd("cd: not a directory: ", 2);
	else if (access(rest, X_OK))
		ft_putstr_fd("cd: permission denied: ", 2);
	ft_putendl_fd(rest, 2);
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
			ft_putstr_fd("cd: string not in pwd: ", 2);
			ft_putendl_fd(line[1], 2);
			*c = 0;
	}
	else
	{
		tmp = path_correc(line[1], *env);
	}
	return (0);
}

/*
if (chdir(rest))
	check_file(rest, c);
else
	change_env_path(rest, env, c);
ft_strdel(&rest);
*/