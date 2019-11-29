/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arcon.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 21:46:50 by awali-al          #+#    #+#             */
/*   Updated: 2018/10/22 22:00:56 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_arcon(char **ar)
{
	size_t	i;
	size_t	n;
	char	*out;

	i = 0;
	n = 0;
	while (ar[i])
	{
		n += ft_strlen(ar[i]);
		i++;
	}
	if (!(out = ft_strnew(n)))
		return (NULL);
	i = 0;
	while (ar[i])
	{
		out = ft_strcat(out, ar[i]);
		i++;
	}
	out[n] = '\0';
	return (out);
}
