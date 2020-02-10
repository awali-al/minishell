/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:07:02 by awali-al          #+#    #+#             */
/*   Updated: 2020/01/15 15:53:51 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		*program_path(char *cmd, int *c)
{
	struct stat		s;

	if (access(cmd, F_OK))
		ft_putstr_fd("minishell: no such file or directory: ", 2);
	else if (access(cmd, X_OK))
		ft_putstr_fd("minishell: permission denied: ", 2);
	else if (!stat(cmd, &s) && S_ISDIR(s.st_mode))
	{
		*c = 0;
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": is a directory", 2);
		return (NULL);
	}
	else
		return (ft_strdup(cmd));
	*c = 0;
	ft_putendl_fd(cmd, 2);
	return (NULL);
}

static char	*lookup(char *cmd, char *fold)
{
	char			*ret;
	char			*tmp;
	DIR				*fd;
	struct dirent	*sd;

	if (!(fd = opendir(fold)) || !ft_strcmp(cmd, ".") || !ft_strcmp(cmd, ".."))
	{
		fd ? closedir(fd) : 0;
		return (NULL);
	}
	tmp = ft_strjoin(fold, "/");
	while ((sd = readdir(fd)))
		if (!ft_strcmp(cmd, sd->d_name))
		{
			ret = ft_strjoin(tmp, cmd);
			ft_strdel(&tmp);
			return (ret);
		}
	ft_strdel(&tmp);
	closedir(fd);
	return (NULL);
}

char		*command_path(char *cmd, char **syspath, int *c)
{
	char			*path;
	int				i;

	i = 0;
	path = NULL;
	if (syspath)
		while (syspath[i])
		{
			if ((path = lookup(cmd, syspath[i])))
				break ;
			i++;
		}
	if (path && !access(path, X_OK))
		return (path);
	else if (path)
		ft_putstr_fd("minishell: permission denied: ", 2);
	else
		ft_putstr_fd("minishell: command not found: ", 2);
	ft_putendl_fd(cmd, 2);
	ft_strdel(&path);
	*c = 0;
	return (NULL);
}
