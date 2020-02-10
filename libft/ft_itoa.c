/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 04:48:09 by awali-al          #+#    #+#             */
/*   Updated: 2018/10/20 03:32:53 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*job(int n, int i)
{
	char	*na;

	if (!(na = ft_strnew(i)))
		return (NULL);
	if (n < 0)
	{
		n = -n;
		na[0] = '-';
	}
	i--;
	while (n)
	{
		na[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return (na);
}

static char	*newa(int n)
{
	int		i;
	int		nb;
	char	*na;

	i = 0;
	nb = n;
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb)
	{
		i++;
		nb /= 10;
	}
	if (!(na = job(n, i)))
		return (NULL);
	return (na);
}

char		*ft_itoa(int n)
{
	char	*out;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (!(out = newa(n)))
		return (NULL);
	return (out);
}
