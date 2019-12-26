/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:56:26 by awali-al          #+#    #+#             */
/*   Updated: 2019/12/26 01:26:29 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		run_command(char **cmd, char **line, char **env, int *c)
{
	pid_t	father;
	int		status;

	father = fork();
	if (father)
	{
		wait(&status);
		*c = status ? 0 : 1;
	}
	else
		execve(*cmd, line, env);
	ft_strdel(&(*cmd));
}
