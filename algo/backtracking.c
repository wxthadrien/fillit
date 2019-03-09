/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 12:28:48 by hmeys             #+#    #+#             */
/*   Updated: 2019/03/08 14:47:10 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

int		ft_check_place(t_tetro new, char **tab, int cote)
{
	t_calcul p;

	p.i = 0;
	while (p.i < 4)
	{
		if ((new.h[p.i].x + new.p0x) == cote ||\
			(new.h[p.i].y + new.p0y) == cote)
			return (-1);
		p.i++;
	}
	p.i = 0;
	while (p.i < 4)
	{
		if ((new.h[p.i].x + new.p0x) < 0 || (new.h[p.i].y + new.p0y) < 0)
			return (-1);
		p.i++;
	}
	p.i = 0;
	while (p.i < 4)
	{
		if (tab[new.h[p.i].x + new.p0x][new.h[p.i].y + new.p0y] != '.')
			return (-1);
		p.i++;
	}
	return (0);
}

int		ft_backtraking(char ***tab, t_tetro *new, int *cote, int num)
{
	char	**tab2;
	t_calcul coord;

	coord.cote = cote;
	coord.i = 0;
	tab2 = *tab;
	if (num < 0)
		return (-1);
	while (ft_check_place(new[num], tab2, *coord.cote) == -1)
	{
		coord.x = num;
		if (ft_under_back(new, tab2, tab, coord) == -1)
			return (-1);
	}
	while (coord.i < 4)
	{
		tab2[new[num].p0x + new[num].h[coord.i].x][new[num].p0y +\
			new[num].h[coord.i].y] = ft_hashtag_to_letter(num);
		coord.i++;
	}
	return (0);
}

void	ft_test_back(char ***tab, t_tetro *new, char **tab2, t_calcul coord)
{
	while (coord.i < 4)
	{
		tab2[new[coord.x - 1].p0x + new[coord.x - 1].h[coord.i].x]\
			[new[coord.x - 1].p0y + new[coord.x - 1].h[coord.i].y] = '.';
		coord.i++;
	}
	coord.i = 0;
	if (new[coord.x - 1].p0y < (*coord.cote - 1))
		new[coord.x - 1].p0y++;
	else if (new[coord.x - 1].p0x < (*coord.cote - 1))
	{
		new[coord.x - 1].p0y = 0;
		new[coord.x - 1].p0x++;
	}
}

int		ft_under_back(t_tetro *new, char **tab2, char ***tab, t_calcul coord)
{
	if (new[coord.x].p0y < (*coord.cote - 1))
		new[coord.x].p0y++;
	else if (new[coord.x].p0x < (*coord.cote - 1))
	{
		new[coord.x].p0y = 0;
		new[coord.x].p0x++;
	}
	else
	{
		if (coord.x == 0)
			return (-1);
		ft_test_back(tab, new, tab2, coord);
		if (ft_backtraking(tab, new, coord.cote, coord.x - 1) == -1)
			return (-1);
		else
		{
			new[coord.x].p0y = 0;
			new[coord.x].p0x = 0;
		}
	}
	return (0);
}
