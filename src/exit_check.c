/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 11:35:54 by awali-al          #+#    #+#             */
/*   Updated: 2020/01/04 14:50:10 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	check(char *str, int i)
{
	char	*tmp;
	int		j;

	j = i;
	while (str[j])
	{
		if (!ft_isdigit(str[j]))
			return (0);
		j++;
	}
	tmp = ft_strsub(str, i, j - i);
	j = ft_atoi(tmp);
	ft_strdel(&tmp);
	return (j);
}

int			exit_check(char *line)
{
	char	*str;
	int		i;
	int		j;

	str = ft_strtrim(line);
	if ((ft_strstr(str, "exit") == str))
	{
		i = 4;
		while (str[i] && space_tab(str[i]))
			i++;
		j = check(str, i);
		ft_strdel(&str);
		ft_strdel(&line);
		exit(j);
	}
	else
	{
		ft_strdel(&str);
		return (1);
	}
}
