/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:39:23 by awali-al          #+#    #+#             */
/*   Updated: 2018/10/17 15:07:49 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char *res;

	res = (char*)dest;
	while (*res)
		res++;
	while (*src && n)
	{
		*res = *src;
		res++;
		src++;
		n--;
	}
	*res = '\0';
	return ((char*)dest);
}
