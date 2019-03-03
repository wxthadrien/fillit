/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:40:03 by hmeys             #+#    #+#             */
/*   Updated: 2019/03/03 15:51:20 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

char		ft_hashtag_to_letter(char c)
{
	char	ret;

	ret = (c + 65);
	return (ret);
}

t_tetro		ft_calcul_place(char **tab)
{
	t_tetro	position_tetro = {0, 0};
	t_tetro	position_absolue = {0, 0};
	t_calcul pos = {0, 0, 0, 0};

	while (pos.x < 4)
	{
		while (pos.y < 4)
		{
			if (tab[pos.x][pos.y] == '.')
				pos.y++;
			else
			{
				position_tetro.h[pos.p].x = pos.x;
				position_tetro.h[pos.p].y = pos.y;
				pos.y++;
				pos.p++;
			}
		}
		pos.y = 0;
		pos.x++;
	}
	return(ft_pos(pos, position_tetro, position_absolue));
}

t_tetro ft_pos(t_calcul pos, t_tetro position_tetro, t_tetro position_absolue)
{
	while (pos.i < 4)
	{
		position_absolue.h[pos.i].x = 0;
		position_absolue.h[pos.i].x = position_tetro.h[pos.i].x - position_tetro.h[0].x;
		pos.i++;
	}
	pos.i = 0;
	while (pos.i < 4)
	{
		position_absolue.h[pos.i].y = 0;
		position_absolue.h[pos.i].y = position_tetro.h[pos.i].y - position_tetro.h[0].y;
		pos.i++;
	}
	position_absolue.p0x = 0;
	position_absolue.p0y = 0;
	return (position_absolue);
}
/*
char		**ft_agrandir_cote(char **tab, int cote)
{
	int i;
	int y;

	i = 0;
	y = 0;
	ft_free_tab(tab, (2));
	if(!(tab = malloc(cote * sizeof(*tab))))
		return (NULL);
	while (i < cote)
	{
		if(!(tab[i] = malloc((cote + 1) * sizeof(**tab))))
			return (NULL);
		i++;
	}
	i = 0;
	while (y < cote)
	{
		while (i < cote)
		{
			tab[y][i] = '.';
			i++;
		}
		i = 0;
		y++;
	}
	return (tab);
}
*/

void			ft_free_tab(char **tab, int n)
{
	int i;

	if (n == 0 || n == -1)
		return ;
	i = 0;
	if(tab == NULL)
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

char		**ft_copier_agrandir(char **tab, int cote)
{
	int		i;
	int		y;
	char	**new_tab;

	i = 0;
	y = 0;
	if(!(new_tab = malloc(cote * sizeof(*new_tab))))
		return (NULL);
	while (i < cote)
	{
		if(!(new_tab[i] = malloc((cote + 1) * sizeof(**new_tab))))
			return (NULL);
		i++;
	}
	i = 0;
	while (y < cote)
	{
		while (i < cote)
		{
			if (i < (cote - 1) && y < (cote - 1))
			{
				if (tab[y][i] == '#')
					new_tab[y][i] = '#';
				else
					new_tab[y][i] = '.';
			}
			else
				new_tab[y][i] = '.';
			i++;
		}
		i = 0;
		y++;
	}
	ft_free_tab(tab, cote - 1);
	return (new_tab);
}
