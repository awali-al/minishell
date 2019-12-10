/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:13:40 by awali-al          #+#    #+#             */
/*   Updated: 2019/12/10 18:20:31 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

/*
static int		arg_end(char	*str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '\'' && str[i] != '\"' && !space_tab(str[i]))
		i++;
	return (i);
}

static int		arg_len(char *line, int *i)
{
	char	*c;
	char	x;

	while(space_tab(line[*i]))
		(*i)++;
	if (line[*i] == '\'' || line[*i] == '\"')
	{
		x = line[*i];
		(*i)++;
		if ((c = ft_strchr(line + *i, x)))
			return (c - (line + *i));
		else
			return (ft_strlen(line + *i));
	}
	else
		return (arg_end(line + *i));
}

static t_arg	*new_node(char *line, int *i)
{
	t_arg	*ret;
	int		c;
	int		j;

	c = 0;
	j = 0;
	ret = (t_arg*)malloc(sizeof(t_arg));
	j = arg_len(line, i);
	ret->str = ft_strsub(line, *i, j);
	ret->nxt = NULL;
	*i += j;
	if (line[*i] == '\'' || line[*i] == '\"')
		(*i)++;
	return (ret);
}

static int		arg_list(t_arg **head, char *line)
{
	t_arg	*tmp;
	int		c;
	int		i;
	
	i = 0;
	c = 1;
	*head = new_node(line, &i);
	tmp = *head;
	while (line[i] != '\0')
	{
		tmp->nxt = new_node(line, &i);
		c++;
		tmp = tmp->nxt;
	}
	return (c);
}

char			**line_treat(char *line, char **env)
{
	t_arg	*head;
	t_arg	*temp;
	char	**ret;
	char	*str;
	int		i;

	str = ft_strtrim(line);
	head = NULL;
	i = arg_list(&head, str);
	temp = head;
	ret = (char**)malloc((i + 1) * sizeof(char*));
	ret[i] = NULL;
	i = 0;
	while (temp)
	{
		ret[i] = ft_strdup(temp->str);
		temp = temp->nxt;
		i++;
	}
	ft_strdel(&str);
	free_list(head);
	(void)env;
	// variables(&ret, env);
	return (ret);
}
*/
