/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:38:58 by awali-al          #+#    #+#             */
/*   Updated: 2018/10/16 03:26:49 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*src;
	char	ch;
	size_t	i;

	i = 0;
	src = (char*)s;
	ch = (char)c;
	while (i < n)
	{
		if (ch == src[i])
			return ((void*)(src + i));
		i++;
	}
	return (NULL);
}
