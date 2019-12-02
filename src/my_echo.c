/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminewalialami <aminewalialami@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:22:04 by awali-al          #+#    #+#             */
/*   Updated: 2019/12/01 17:12:08 by aminewalial      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		my_echo(char **line, char **env, int *c)
{
	char	*tmp;
	int		i;
	int		n;

	n = 0;
	if (!ft_strcmp(line[i], "-n"))
		n = 1;
	i = 1 + n;
	while (line[i])
	{
		if (line[i][0])
		{
			ft_putstr(tmp);
			if (line[++i])
				write(1, " ", 1);
			else if (!n)
				write(1, "\n", 1);
			ft_strdel(&tmp);
		}
	}
}
