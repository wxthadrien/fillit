/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:40:03 by hmeys             #+#    #+#             */
/*   Updated: 2019/03/10 18:00:33 by losuna-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	ft_hashtag_to_letter(char c)
{
	char	ret;

	ret = (c + 65);
	return (ret);
}

t_tetro	ft_calcul_place(char **tab)
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

void	ft_free_tab(char **tab, int n)
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
