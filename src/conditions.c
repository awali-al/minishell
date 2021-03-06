/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 22:17:36 by awali-al          #+#    #+#             */
/*   Updated: 2020/01/04 14:49:27 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		space_tab(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	else
		return (0);
}

int		username_char(char c)
{
	if (ft_isalnum(c) || c == '-' || c == '_' || c == '.')
		return (1);
	else
		return (0);
}

int		variable_char(char c)
{
	if (ft_isalnum(c) || c == '_')
		return (1);
	else
		return (0);
}
