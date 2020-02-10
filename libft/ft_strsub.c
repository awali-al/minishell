/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:03:18 by awali-al          #+#    #+#             */
/*   Updated: 2018/10/19 21:33:01 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	sub = ft_strnew(len);
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = *(s + start);
		i++;
		s++;
	}
	sub[i] = '\0';
	return (sub);
}
