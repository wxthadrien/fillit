/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:40:03 by hmeys             #+#    #+#             */
/*   Updated: 2019/03/08 14:23:08 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

char		ft_hashtag_to_letter(char c)
{
	char	ret;

	ret = (c + 65);
	return (ret);
}

t_tetro			ft_calcul_place(char **tab)
{
	t_tetro		position_tetro[2];
	t_calcul	pos;

	pos.x = 0;
	pos.y = 0;
	pos.p = 0;
	pos.i = 0;
	while (pos.x < 4)
	{
		while (pos.y < 4)
		{
			if (tab[pos.x][pos.y] == '.')
				pos.y++;
			else
			{
				position_tetro[0].h[pos.p].x = pos.x;
				position_tetro[0].h[pos.p].y = pos.y;
				pos.y++;
				pos.p++;
			}
		}
		pos.y = 0;
		pos.x++;
	}
	return (ft_pos(pos, position_tetro[0], position_tetro[1]));
}

t_tetro	ft_pos(t_calcul pos, t_tetro position_tetro, t_tetro position_absolue)
{
	while (pos.i < 4)
	{
		position_absolue.h[pos.i].x = 0;
		position_absolue.h[pos.i].x = position_tetro.h[pos.i].x\
			- position_tetro.h[0].x;
		pos.i++;
	}
	pos.i = 0;
	while (pos.i < 4)
	{
		position_absolue.h[pos.i].y = 0;
		position_absolue.h[pos.i].y = position_tetro.h[pos.i].y\
			- position_tetro.h[0].y;
		pos.i++;
	}
	position_absolue.p0x = 0;
	position_absolue.p0y = 0;
	return (position_absolue);
}

char		**ft_agrandir_cote(char **tab, int cote)
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

void			ft_free_tab(char **tab, int n)
{
	int i;

	i = 0;
	if (tab == NULL)
		return ;
	while (i < n)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

int			remplir_tab(char **tab, char **new_tab, t_calcul coord)
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

char			**ft_copier_agrandir(char **tab, int cote)
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
