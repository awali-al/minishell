/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:56:26 by awali-al          #+#    #+#             */
/*   Updated: 2020/01/04 19:57:45 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		run_command(char **cmd, char **line, char **env, int *c)
{
	pid_t	father;
	int		status;

	if ((father = fork()) < 0)
		ft_putendl_fd("fork has failed", 2);
	else if (father == 0)
		execve(*cmd, line, env);
	else
	{
		wait(&status);
		*c = status ? 0 : 1;
	}
	ft_strdel(&(*cmd));
}
