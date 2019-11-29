/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:39:41 by awali-al          #+#    #+#             */
/*   Updated: 2019/11/28 16:28:22 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		**var_home(char **line, char **env)
{
    char	**ret;
    char	*home;
    int		i;

    i = 0;
    while (line[i])
        i++;
    ret = (char**)malloc((i + 1) * sizeof(char*));
    ret[i] = NULL;
    home = value_of(env, "HOME");
    i = 0;
    while (line[i])
    {
        if (line[i][0] == '~')
            ret[i] = ft_strjoin(home, line[i] + 1);
        ft_strdel(&line[i]);
        i++;
    }
}