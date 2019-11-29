/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 11:48:41 by awali-al          #+#    #+#             */
/*   Updated: 2018/10/20 22:04:46 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**job(const char *s, char c)
{
	int		i;
	int		j;
	char	**ar;

	i = 1;
	j = 0;
	if (!s)
		return (NULL);
	if (s[0] != c)
		j++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			j++;
		i++;
	}
	if (j == 0)
	{
		ar = (char**)malloc(sizeof(char*));
		ar[0] = ft_strnew(1);
		return (ar);
	}
	if (!(ar = (char**)malloc((j + 1) * sizeof(char*))))
		return (NULL);
	return (ar);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**ar;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!(ar = job(s, c)))
		return (NULL);
	while (s[i] != '\0')
	{
		k = 0;
		while (s[i + k] != '\0' && s[i + k] != c)
			k++;
		if (k > 0)
		{
			ar[j] = ft_strsub(s, i, k);
			j++;
			i = i + k - 1;
		}
		i++;
	}
	ar[j] = NULL;
	return (ar);
}
