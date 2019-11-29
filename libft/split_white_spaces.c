/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_white_spaces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:03:13 by awali-al          #+#    #+#             */
/*   Updated: 2019/11/06 23:29:05 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	white_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	else
		return (0);
}

static int	word_num(char *str)
{
	int		i;
	int		c;

	i = 1;
	if (str)
	{
		c = 1;
		while (str[i])
		{
			if (!white_space(str[i]) && white_space(str[i - 1]))
				c++;
			i++;
		}
		return (c);
	}
	return (0);
}

static char	*word(char *str, int *j)
{
	char	*tmp;
	int		i;
	int		n;

	tmp = str + *j;
	i = 0;
	while (tmp[i] && !white_space(tmp[i]))
		i++;
	n = i;
	while (tmp[i] && white_space(tmp[n]))
		n++;
	*j += n;
	return (ft_strndup(tmp, i));
}

char		**split_white_spaces(char *str)
{
	char	**ret;
	char	*tmp;
	int		n;
	int		i;
	int		j;

	n = 0;
	while (str[n] && white_space(str[n]))
		n++;
	tmp = ft_strdup(str + n);
	n = word_num(tmp);
	if (!(ret = (char**)malloc((n + 1) * sizeof(char*))))
		return (NULL);
	ret[n] = NULL;
	i = 0;
	j = 0;
	while (i < n)
	{
		ret[i] = word(tmp, &j);
		i++;
	}
	ft_strdel(&tmp);
	return (ret);
}
