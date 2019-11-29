/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 23:54:54 by awali-al          #+#    #+#             */
/*   Updated: 2018/10/22 00:12:53 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnmap(t_list *lst, t_list *(*f)(t_list *elem), int n)
{
	t_list	*r;

	if (!lst || !n)
		return (NULL);
	r = (t_list*)malloc(sizeof(t_list));
	r = f(lst);
	r->next = ft_lstnmap(lst->next, f, n - 1);
	return (r);
}
