/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:56:26 by awali-al          #+#    #+#             */
/*   Updated: 2019/11/13 14:41:56 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	father_process(char *cmd, char *line, char ***env, int *c)
{
	char	*rest;

	rest = ft_strchr(line, ' ') + 1;
	return (1);
}

void		run_command(char *cmd, char *line, char ***env, int *c)
{
	pid_t	father;
	char	**av;
	int		status;

	av = ft_strsplit(line, ' ');
	if (father_process(cmd, line, env, c))
	{
		father = fork();
		if (father)
		{
			wait(&status);
			*c = status ? 0 : 1;
		}
		else
			execve(cmd, av, env);
	}
}
