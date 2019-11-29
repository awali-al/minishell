/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 18:31:00 by awali-al          #+#    #+#             */
/*   Updated: 2018/10/21 23:43:47 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*r;

	if (!lst)
		return (NULL);
	r = (t_list*)malloc(sizeof(t_list));
	r = f(lst);
	r->next = ft_lstmap(lst->next, f);
	return (r);
}
