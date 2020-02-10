/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:25:38 by awali-al          #+#    #+#             */
/*   Updated: 2018/10/19 21:32:15 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*ch;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	ch = ft_strnew(ft_strlen(s));
	if (!ch)
		return (NULL);
	while (s[i])
	{
		ch[i] = f((char)s[i]);
		i++;
	}
	ch[i] = '\0';
	return (ch);
}
