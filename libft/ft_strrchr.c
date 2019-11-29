/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 02:05:16 by awali-al          #+#    #+#             */
/*   Updated: 2018/10/18 23:06:45 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;

	i = ft_strlen(s);
	if (c == '\0')
		return ((char*)(s + i));
	while (i && (char)c != s[i - 1])
		i--;
	if (i)
		return ((char*)(s + i - 1));
	else
		return (NULL);
}
