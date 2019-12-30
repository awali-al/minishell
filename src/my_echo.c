/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:22:04 by awali-al          #+#    #+#             */
/*   Updated: 2019/12/30 21:56:07 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		my_echo(char **line, int *c)
{
	int		i;
	int		n;

	n = 0;
	while (line[n])
		n++;
	n = 0;
	if (!ft_strcmp(line[1], "-n"))
		n = 1;
	i = 1 + n;
	while (line[i])
	{
		if (line[i][0])
		{
			ft_putstr(line[i]);
			if (line[++i] && line[i][0])
				write(1, " ", 1);
			else if (!n)
				write(1, "\n", 1);
		}
		else
			i++;
	}
	*c = 1;
}
