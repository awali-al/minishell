/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:07:02 by awali-al          #+#    #+#             */
/*   Updated: 2020/01/04 15:34:41 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		*program_path(char *cmd, int *c)
{
	if (access(cmd, F_OK))
	{
		*c = 0;
		ft_putstr_fd("minishell: no such file or directory: ", 2);
		ft_putendl_fd(cmd, 2);
		return (NULL);
	}
	else if (access(cmd, X_OK))
	{
		*c = 0;
		ft_putstr_fd("minishell: permission denied: ", 2);
		ft_putendl_fd(cmd, 2);
		return (NULL);
	}
	else
		return (ft_strdup(cmd));
}

static char	*lookup(char *cmd, char *fold)
{
	char			*ret;
	char			*tmp;
	DIR				*fd;
	struct dirent	*sd;

	fd = opendir(fold);
	perror("opendir: ");
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
	perror("closedir: ");
	return (NULL);
}

char		*command_path(char *cmd, char **syspath, int *c)
{
	char			*path;
	int				i;

	i = 0;
	if (syspath)
		while (syspath[i])
		{
			path = lookup(cmd, syspath[i]);
			if (path)
				return (path);
			i++;
		}
	*c = 0;
	ft_putstr_fd("minishell: command not found: ", 2);
	ft_putendl_fd(cmd, 2);
	return (NULL);
}
