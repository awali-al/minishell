/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:13:40 by awali-al          #+#    #+#             */
/*   Updated: 2019/12/13 14:48:16 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char		*arg(char *str, int *i, char x)
{
	char	*ret;
	char	*tmp;
	int		j;

	if (x)
	{
		tmp = ft_strchr(str + *i, x);
		if (tmp)
		{
			ret = ft_strsub(str, *i, tmp - (str + *i));
			*i += tmp - (str + *i);
		}
		else
		{
			j = *i;
			
		}
	}
	else
	{
		
	}
	return (ret);
}

static t_arg	*new_node(char *str, int *i)
{
	t_arg	*ret;
	char	*tmp;
	char	x;

	ret = NULL;
	while (space_tab(str[*i]))
		(*i)++;
	if (str[*i])
	{
		if (!(ret = (t_arg*)malloc(sizeof(t_arg))))
			return (NULL);
		ret->nxt = NULL;
		if (str[*i] == '\'' || str[*i] == '\"')
		{
			x = str[*i];
			*i++;
			ret->str = arg(str, i, x);
		}
		else
			ret->str = arg(str, i, '\0');
	}
	return (ret);
}

static int		list_fill(t_arg **head, char *str)
{
	t_arg	*tmp;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	*head = new_node(str, &i);
	tmp = *head;
	if (tmp)
	{
		ret++;
		while (str[i])
		{
			tmp->nxt = new_node(str, &i);
			ret++;
			tmp = tmp->nxt;
		}
	}
	return (ret);
}

static char		**arr_fill(t_arg *head, int n)
{
	t_arg	*tmp;
	char	**ret;
	int		i;

	if (n)
	{
		tmp = head;
		if (!(ret = (char**)maloc((n + 1) * sizeof(char*))))
			return (NULL);
		ret[n] = NULL;
		i = 0;
		while (i < n && tmp)
		{
			ret[i] = var(tmp->str);
			i++;
			tmp = tmp->nxt;
		}
		return (ret);
	}
	else
		return (NULL);
}

char			**line_treat(char *line, char **env)
{
	t_arg	*head;
	char	**ret;
	char	*str;
	int		n;

	str = ft_strtrim(line);
	head = NULL;
	n = list_fill(&head, str);
	ft_strdel(&str);
	ret = arr_fill(head, n);
	free_list(head);
	return (ret);
}
