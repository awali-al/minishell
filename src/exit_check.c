/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 11:35:54 by awali-al          #+#    #+#             */
/*   Updated: 2020/01/22 19:22:42 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			exit_check(char *line, char **av)
{
	char	*str;
	int		j;

	(void)av;
	str = ft_strtrim(line);
	if (str && (ft_strstr(str, "exit") == str))
	{
		j = ft_atoi(str + 4);
		ft_strdel(&str);
		exit(j);
	}
	else
	{
		ft_strdel(&str);
		return (1);
	}
}
