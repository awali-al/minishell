/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:34:30 by awali-al          #+#    #+#             */
/*   Updated: 2020/01/07 12:03:35 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	display_prompt(int c)
{
	char		*col;
	char		*path;
	static char	*tmp;

	if (c)
		col = GREEN_COL;
	else
		col = RED_COL;
	path = getcwd(NULL, 0);
	if (path)
	{
		tmp = ft_strrchr(path, '/');
		tmp = tmp && tmp[1] ? tmp + 1 : path;
		ft_strdel(&path);
	}
	ft_putstr(tmp);
	ft_putstr(col);
	ft_putstr(" $> ");
	ft_putstr(RESET_COL);
}
