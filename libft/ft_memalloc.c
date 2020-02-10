/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 22:02:54 by awali-al          #+#    #+#             */
/*   Updated: 2018/10/16 00:58:32 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*c;

	c = (char*)malloc(size * sizeof(char));
	if (!c)
		return (NULL);
	ft_bzero((void*)c, size);
	return ((void*)c);
}
