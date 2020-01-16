/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 00:08:26 by awali-al          #+#    #+#             */
/*   Updated: 2018/10/19 21:35:13 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	size_t	l1;
	size_t	l2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	res = ft_strnew(l1 + l2);
	if (res == NULL)
		return (NULL);
	res = (char*)ft_memmove(res, s1, l1);
	i = 0;
	while (s2[i])
	{
		res[l1 + i] = s2[i];
		i++;
	}
	res[l1 + l2] = '\0';
	return (res);
}
