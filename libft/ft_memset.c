/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 20:40:01 by awali-al          #+#    #+#             */
/*   Updated: 2018/10/10 23:18:05 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t	i;
	char	*str;
	char	ch;

	i = 0;
	ch = (char)c;
	str = (char*)s;
	while (i < len)
	{
		str[i] = ch;
		i++;
	}
	return ((void*)str);
}
