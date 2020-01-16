/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 10:47:15 by awali-al          #+#    #+#             */
/*   Updated: 2018/10/16 22:21:05 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(const char *dest, const char *src)
{
	char *res;

	res = (char*)dest;
	while (*res)
		res++;
	while (*src)
	{
		*res = *src;
		res++;
		src++;
	}
	*res = '\0';
	return ((char*)dest);
}
