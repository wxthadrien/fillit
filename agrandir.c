/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agrandir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losuna-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 17:59:02 by losuna-b          #+#    #+#             */
/*   Updated: 2019/03/10 18:54:16 by losuna-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_agrandir_cote(char **tab, int cote)
{
	t_coordonnees coord;

	coord.x = 0;
	coord.y = 0;
	ft_free_tab(tab, (2));
	if (!(tab = malloc(cote * sizeof(*tab))))
		return (NULL);
	while (coord.x < cote)
	{
		if (!(tab[coord.x] = malloc((cote + 1) * sizeof(**tab))))
			return (NULL);
		coord.x++;
	}
	coord.x = 0;
	while (coord.y < cote)
	{
		while (coord.x < cote)
		{
			tab[coord.y][coord.x] = '.';
			coord.x++;
		}
		coord.x = 0;
		coord.y++;
	}
	return (tab);
}

int		remplir_tab(char **tab, char **new_tab, t_calcul coord)
{
	if (coord.i < (coord.p - 1) && coord.y < (coord.p - 1))
	{
		if (tab[coord.y][coord.i] == '#')
			new_tab[coord.y][coord.i] = '#';
		else
			new_tab[coord.y][coord.i] = '.';
	}
	else
		new_tab[coord.y][coord.i] = '.';
	coord.i++;
	return (coord.i);
}

char	**ft_copier_agrandir(char **tab, int cote)
{
	t_calcul	coord;
	char		**new_tab;

	coord.i = 0;
	coord.y = 0;
	coord.p = cote;
	if (!(new_tab = malloc(coord.p * sizeof(*new_tab))))
		return (NULL);
	while (coord.i < coord.p)
	{
		if (!(new_tab[coord.i] = malloc((coord.p + 1) * sizeof(**new_tab))))
			return (NULL);
		coord.i++;
	}
	coord.i = 0;
	while (coord.y < coord.p)
	{
		while (coord.i < coord.p)
			coord.i = remplir_tab(tab, new_tab, coord);
		coord.i = 0;
		coord.y++;
	}
	ft_free_tab(tab, coord.p - 1);
	return (new_tab);
}
