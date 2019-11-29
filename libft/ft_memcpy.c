/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 11:59:01 by awali-al          #+#    #+#             */
/*   Updated: 2018/10/10 22:07:36 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*s;
	char	*d;

	s = (char*)src;
	d = (char*)dst;
	i = 0;
	while (i < n)
	{
		if (s[i])
			d[i] = s[i];
		else
			d[i] = '\0';
		i++;
	}
	return (dst);
}
