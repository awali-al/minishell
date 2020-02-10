/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 23:49:13 by awali-al          #+#    #+#             */
/*   Updated: 2018/10/18 23:00:04 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				nb;
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = (unsigned char*)s1;
	st2 = (unsigned char*)s2;
	nb = (int)n;
	if (nb == 0 || (*st1 == '\0' && *st2 == '\0'))
		return (0);
	if (*st1 == *st2)
		return (ft_strncmp(s1 + 1, s2 + 1, (size_t)(n - 1)));
	else
		return (*st1 - *st2);
}
