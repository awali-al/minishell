/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:34:30 by awali-al          #+#    #+#             */
/*   Updated: 2019/10/01 21:16:06 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	display_prompt(int c)
{
	char	*col;

	if (c)
		col = GREEN_COL;
	else
		col = RED_COL;
	ft_putstr(col);
	ft_putstr("$> ");
	ft_putstr(RESET_COL);
}

void	error(char *line, int	*c)
{
	char	*cmd;

	cmd = ft_strndup(line, ft_strchr(line, ' ') - line);
	*c = 0;
	ft_putstr_fd("minishell: command not found: ", 2);
	ft_putstr_fd(cmd, 2);
	free(cmd);
}
