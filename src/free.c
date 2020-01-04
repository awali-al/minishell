/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 21:31:34 by awali-al          #+#    #+#             */
/*   Updated: 2020/01/04 15:39:21 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		free_list(t_arg *head)
{
	t_arg	*next;

	while (head)
	{
		next = head->nxt;
		ft_strdel(&head->str);
		free(head);
		head = next;
	}
}

void		free_2d(char **path)
{
	int		i;

	i = 0;
	if (path)
	{
		while (path[i])
		{
			ft_strdel(&path[i]);
			i++;
		}
		free(path);
	}
}
