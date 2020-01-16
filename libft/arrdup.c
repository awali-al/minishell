/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:28:59 by awali-al          #+#    #+#             */
/*   Updated: 2019/10/22 17:55:34 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**arrdup(char **src)
{
	char	**ret;
	int		i;
	int		n;
	
	n = 0;
	while (src[n])
		n++;
	ret = (char**)malloc((n + 1) * sizeof(char*));
	ret[n] = NULL;
	i = 0;
	while (i < n)
	{
		ret[i] = ft_strdup(src[i]);
		i++;
	}
	return (ret);
}