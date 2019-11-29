/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 01:54:15 by awali-al          #+#    #+#             */
/*   Updated: 2018/10/18 00:58:44 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;

	i = 0;
	while (s[i] && (char)c != s[i])
		i++;
	if (c == '\0')
		return ((char*)(s + i));
	if (i < ft_strlen(s))
		return ((char*)(s + i));
	else
		return (NULL);
}
