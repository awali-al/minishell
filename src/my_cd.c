/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 15:28:53 by awali-al          #+#    #+#             */
/*   Updated: 2019/12/26 21:36:30 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*path_correc(char **line, char **env)
{
	if (!line[1])
		return (ft_strdup(value_of(env, "HOME")));
	else if (!ft_strcmp(line[1], "-"))
		return (ft_strdup(value_of(env, "OLDPWD")));
	else
		return ft_strdup(line[1]);
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
			ft_putstr_fd("cd: string not in pwd: ", 2);
			ft_putendl_fd(line[1], 2);
			*c = 0;
	}
	else
	{
		tmp = path_correc(line, *env);
		if (chdir(tmp))
			check_file(tmp, c);
		else
			change_env_path(tmp, env, c);
		ft_strdel(&tmp);
	}
	return (0);
}
