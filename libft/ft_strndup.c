/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 21:27:37 by awali-al          #+#    #+#             */
/*   Updated: 2018/10/22 21:32:51 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	char	*d;

	i = 0;
	d = (char*)malloc((n + 1) * sizeof(char));
	if (d == NULL)
		return (NULL);
	while (i < n)
	{
		if (s1[i])
			d[i] = s1[i];
		else
			d[i] = '\0';
		i++;
	}
	d[i] = '\0';
	return (d);
}
