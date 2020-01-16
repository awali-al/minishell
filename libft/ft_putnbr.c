/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:27:45 by awali-al          #+#    #+#             */
/*   Updated: 2018/10/16 04:03:14 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long int numb;

	numb = n;
	if (numb < 0)
	{
		ft_putchar('-');
		numb = numb * -1;
	}
	if (numb > 9)
		ft_putnbr(numb / 10);
	ft_putchar(numb % 10 + '0');
}
