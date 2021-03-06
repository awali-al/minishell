/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 10:26:37 by awali-al          #+#    #+#             */
/*   Updated: 2020/01/04 15:34:56 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	**system_path(char **env)
{
	int		i;

	i = 0;
	while (env[i] && env[i] != ft_strstr(env[i], "PATH="))
		i++;
	if (env[i])
		return (ft_strsplit(ft_strchr(env[i], '=') + 1, ':'));
	else
		return (NULL);
}

static int	system_command(char *cmd, char **line, char ***env, int *c)
{
	if (!ft_strcmp(cmd, "echo"))
		my_echo(line, c);
	else if (!ft_strcmp(cmd, "cd"))
		my_cd(line, env, c);
	else if (!ft_strcmp(cmd, "setenv"))
		my_set(line, env, c);
	else if (!ft_strcmp(cmd, "unsetenv"))
		my_unset(line, env, c);
	else if (!ft_strcmp(cmd, "env"))
		my_env(*env, c);
	else
		return (0);
	return (1);
}

char		*check_command(char **line, char ***env, int *c)
{
	char	**syspath;
	char	*cmd;
	char	*ret;
	int		i;

	cmd = line[0];
	if (system_command(cmd, line, env, c))
		return (NULL);
	i = 0;
	syspath = system_path(*env);
	if (ft_strchr(cmd, '/'))
		ret = program_path(cmd, c);
	else
		ret = command_path(cmd, syspath, c);
	free_2d(syspath);
	return (ret);
}
