/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 19:26:08 by awali-al          #+#    #+#             */
/*   Updated: 2018/10/20 20:57:59 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*l;

	if (!(l = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		l->content = NULL;
		l->content_size = 0;
		l->next = NULL;
	}
	else
	{
		if (!(l->content = malloc(content_size)))
			return (NULL);
		l->content = ft_memcpy(l->content, content, content_size);
		l->content_size = content_size;
		l->next = NULL;
	}
	return (l);
}
