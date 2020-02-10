/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 22:03:52 by awali-al          #+#    #+#             */
/*   Updated: 2018/10/17 14:45:23 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	i = len;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	if (d > s && d <= (s + len))
		while (i)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	else
		d = ft_memcpy(d, s, len);
	return (d);
}
