/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 14:35:36 by hmeys             #+#    #+#             */
/*   Updated: 2018/10/29 10:09:12 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				i;
	unsigned long	nbr;
	int				negative;

	nbr = 0;
	negative = 0;
	i = 0;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\r') ||
			(str[i] == ' ') || (str[i] == '\v') || (str[i] == '\f'))
		i++;
	if (str[i] == '-')
		negative = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr *= 10;
		nbr += (int)str[i] - '0';
		i++;
	}
	if (nbr > 9223372036854775807)
		return ((negative == 1) ? 0 : -1);
	if (negative == 1)
		return (-nbr);
	return (nbr);
}
