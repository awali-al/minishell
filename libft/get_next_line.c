/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 16:35:15 by awali-al          #+#    #+#             */
/*   Updated: 2019/11/20 18:53:08 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*s_stock(char *s, char *tmp)
{
	char		*p;

	p = s;
	s = ft_strjoin(p, tmp);
	free(p);
	return (s);
}

static char	*s_free(char *s, int i)
{
	char		*p;
	int			i;

	p = s;
	s = ft_strdup(p + i + 1);
	free(p);
	return (s);
}

int			get_next_line(const int fd, char **line)
{
	int			i;
	char		tmp[BUFF_SIZE + 1];
	static char	*s;

	!s ? s = ft_strnew(1) : 0;
	if (fd < 0 || !line || read(fd, tmp, 0) == -1 || BUFF_SIZE < 1)
		return (-1);
	while ((i = read(fd, tmp, BUFF_SIZE)))
	{
		tmp[i] = '\0';
		s = s_stock(s, tmp);
		if (ft_strchr(s, '\n'))
			break ;
	}
	if (*s == '\0')
	{
		*line = NULL;
		return (0);
	}
	i = ft_strchr(s, '\n') - s;
	*line = ft_strndup(s, i);
	s = s_free(s, i);
	return (1);
}
