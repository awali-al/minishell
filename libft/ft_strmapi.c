/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:53:25 by awali-al          #+#    #+#             */
/*   Updated: 2018/10/19 21:14:51 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ch;

	if (!s)
		return (NULL);
	ch = ft_strnew(ft_strlen(s));
	if (!ch)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ch[i] = f(i, s[i]);
		i++;
	}
	ch[i] = '\0';
	return (ch);
}
