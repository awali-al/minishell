/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 15:32:12 by awali-al          #+#    #+#             */
/*   Updated: 2018/10/15 15:34:16 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int numb;

	numb = n;
	if (numb < 0)
	{
		ft_putchar_fd('-', fd);
		numb = numb * -1;
	}
	if (numb > 9)
		ft_putnbr_fd(numb / 10, fd);
	ft_putchar_fd(numb % 10 + '0', fd);
}
