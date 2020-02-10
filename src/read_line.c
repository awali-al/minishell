/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 11:46:22 by awali-al          #+#    #+#             */
/*   Updated: 2020/01/23 12:59:40 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	read_line(char **line)
{
	char	*tmp;
	char	buf[2];
	int		i;

	tmp = ft_strnew(1);
	while ((i = read(0, &buf, 1)))
	{
		buf[1] = '\0';
		if (buf[0] == '\n')
			break ;
		*line = ft_strjoin(tmp, buf);
		ft_strdel(&tmp);
		tmp = *line;
	}
	if (!i)
	{
		write(1, "\n", 1);
		ft_strdel(line);
	}
}
