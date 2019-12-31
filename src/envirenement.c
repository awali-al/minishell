/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envirenement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 11:06:42 by awali-al          #+#    #+#             */
/*   Updated: 2019/12/31 00:13:22 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		change_env_path(char *path, char ***env, int *c)
{
	char	*pwd;
	int		i;

	pwd = value_of(*env, "PWD");
	i = 0;
	while ((*env)[i] && ft_strstr((*env)[i], "OLDPWD=") != (*env)[i])
		i++;
	// if (!env[i])
	// 	new_env()
	
	ft_strdel(&((*env)[i]));
	(*env)[i] = ft_strjoin("OLDPWD=", pwd);
	i = 0;
	while (ft_strstr((*env)[i], "PWD=") != (*env)[i])
		i++;
	ft_strdel(&((*env)[i]));
	(*env)[i] = ft_strjoin("PWD=", path);
	*c = 1;
}

char		*value_of(char **env, char *key)
{
	char	*ret;
	char	*tmp;
	int		i;

	i = 0;
	ret = NULL;
	tmp = ft_strjoin(key, "=");
	while (env[i] && ft_strstr(env[i], tmp) != env[i])
		i++;
	ft_strdel(&tmp);
	if (env[i])
		ret = ft_strchr(env[i], '=') + 1;
	return (ret);
}

char	**my_envirenement(char **env)
{
	char	**ret;
	int		n;
	int		i;

	i = 0;
	n = 0;
	while (env[n])
		n++;
	ret = (char**)malloc((n + 1) * sizeof(char*));
	while (i < n)
	{
		ret[i] = ft_strdup(env[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
