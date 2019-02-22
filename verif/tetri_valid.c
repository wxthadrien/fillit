/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 13:15:48 by hmeys             #+#    #+#             */
/*   Updated: 2019/02/22 16:50:20 by losuna-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "verif.h"

int		ft_tetri_valid(char *tab)
{
	int	x;
	int	point;
	int	number;
	int	ok;

	ok = 0;
	number = 0;
	point = 0;
	x = 0;
	while (tab[x] && tab[x] != '\n')
	{
		if (tab[x] != '.' && tab[x] != '1' && tab[x] != '2' && tab[x] != '3')
			return (-1);
		if (tab[x] == '.')
			point++;
		if (tab[x] == '1' || tab[x] == '2' || tab[x] == '3')
			number++;
		if (tab[x] == '2' || tab[x] == '3')
			ok = 1;
		x++;
	}
	if (number != 4 || point != 12 || ok == 0 || ft_strlen(tab) != 16)
		return (-1);
	return (0);
}
