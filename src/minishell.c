/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 08:56:18 by awali-al          #+#    #+#             */
/*   Updated: 2020/01/07 14:25:08 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		main(int ac, char **av, char **env)
{
	char	**arr;
	char	*line;
	char	*cmd;

	(void)av;
	ac = 1;
	env = my_envirenement(env);
	line = ft_strdup("hi");
	while (exit_check(line))
	{
		ft_strdel(&line);
		display_prompt(ac);
		read_line(&line);
		arr = line_treat(line, env);
		if (arr && ft_strcmp(arr[0], "exit"))
		{
			if ((cmd = check_command(arr, &env, &ac)))
				run_command(&cmd, arr, env, &ac);
			free_2d(arr);
		}
		else if (!arr)
			write(1, "\n", 1);
	}
	line ? ft_strdel(&line) : 0;
}
