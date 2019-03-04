/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 12:28:48 by hmeys             #+#    #+#             */
/*   Updated: 2019/02/22 17:05:33 by losuna-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

int		ft_check_place(t_tetro new, char **tab, int cote)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if ((new.h[i].x + new.p0x) == cote || (new.h[i].y + new.p0y) == cote)
			return (-1);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if ((new.h[i].x + new.p0x) < 0 || (new.h[i].y + new.p0y) < 0)
			return (-1);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (tab[new.h[i].x + new.p0x][new.h[i].y + new.p0y] != '.')
			return (-1);
		i++;
	}
	return (0);
}

int		ft_backtraking(char ***tab, t_tetro *new, int *cote, int num)
{
	int i;
	char **tab2;

	i = 0;
	tab2 = *tab;
	if (num < 0)
		return (-1);
	while (ft_check_place(new[num], tab2, *cote) == -1)
	{
		if (new[num].p0y < (*cote - 1))
			new[num].p0y++;
		else if (new[num].p0x < (*cote - 1))
		{
			new[num].p0y = 0;
			new[num].p0x++;
		}
		else
		{
			if (num == 0)
				return (-1);
			while (i <  4)
			{
				tab2[new[num - 1].p0x + new[num - 1].h[i].x][new[num - 1].p0y + new[num - 1].h[i].y] = '.';
				i++;
			}
			i = 0;
			if (new[num - 1].p0y < (*cote - 1))
				new[num - 1].p0y++;
			else if (new[num - 1].p0x < (*cote - 1))
			{
				new[num - 1].p0y = 0;
				new[num - 1].p0x++;
			}
			if (ft_backtraking(tab, new, cote, num - 1) == -1)
				return (-1);
			else
			{
				new[num].p0y = 0;
				new[num].p0x = 0;
			}
		}
	}
	while (i <  4)
	{
		tab2[new[num].p0x + new[num].h[i].x][new[num].p0y + new[num].h[i].y] = ft_hashtag_to_letter(num);
		i++;
	}
	return (0);
}
