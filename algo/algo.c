/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:40:03 by hmeys             #+#    #+#             */
/*   Updated: 2019/02/22 15:15:49 by losuna-b         ###   ########.fr       */
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
	int	x;
	int	y;
	int	p;

	x = 0;
	y = 0;
	p = 0;
	while (x < 4)
	{
		while (y < 4)
		{
			if (tab[x][y] == '.')
				y++;
			else
			{
				position_tetro.h[p].x = x;
				position_tetro.h[p].y = y;
				y++;
				p++;
			}
		}
		y = 0;
		x++;
	}
	position_absolue.h[0].x = 0;
	position_absolue.h[1].x = position_tetro.h[1].x - position_tetro.h[0].x;
	position_absolue.h[2].x = position_tetro.h[2].x - position_tetro.h[0].x;
	position_absolue.h[3].x = position_tetro.h[3].x - position_tetro.h[0].x;
	position_absolue.h[0].y = 0;
	position_absolue.h[1].y = position_tetro.h[1].y - position_tetro.h[0].y;
	position_absolue.h[2].y = position_tetro.h[2].y - position_tetro.h[0].y;
	position_absolue.h[3].y = position_tetro.h[3].y - position_tetro.h[0].y;
	position_absolue.p0x = 0;
	position_absolue.p0y = 0;
	return (position_absolue);
}

char		**ft_agrandir_cote(char **tab, int cote)
{
	int i;
	int y;

	i = 0;
	y = 0;
	ft_free_tab(tab, (2));
	tab = malloc(cote * sizeof(*tab));
	if (tab == NULL)
		return (NULL);
	while (i < cote)
	{
		tab[i] = malloc((cote + 1) * sizeof(**tab));
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

char		**ft_free_tab(char **tab, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
	return (tab);
}

char		**ft_copier_agrandir(char **tab, int cote)
{
	int		i;
	int		y;
	char	**new_tab;

	i = 0;
	y = 0;
	new_tab = malloc(cote * sizeof(*new_tab));
	if (new_tab == NULL)
		return (NULL);
	while (i < cote)
	{
		new_tab[i] = malloc((cote + 1) * sizeof(**new_tab));
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
	ft_free_tab(tab, (cote - 1));
	return (new_tab);
}
