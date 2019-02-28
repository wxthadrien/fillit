/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lorenzo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losuna-b <losuna-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:43:48 by losuna-b          #+#    #+#             */
/*   Updated: 2019/02/22 16:46:36 by losuna-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "verif.h"

char	**ft_tab_converter(char **tab)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < 4)
	{
		while (y < 4)
		{
			if (tab[x][y] == '.')
				y++;
			if (tab[x][y] == '#')
			{
				tab[x][y] = ft_siri(tab, x, y);
				y++;
			}
		}
		y = 0;
		x++;
	}
	return (tab);
}

char	ft_siri(char **tab, int x, int y)
{
	if (x == 0 && y == 0)
		tab[x][y] = ft_str_to_char(ft_itoa(ft_alexa(tab, 1, x, y)));
	else if (x == 0 && (y == 1 || y == 2))
		tab[x][y] = ft_str_to_char(ft_itoa(ft_alexa(tab, 2, x, y)));
	else if ((x == 1 || x == 2) && y == 0)
		tab[x][y] = ft_str_to_char(ft_itoa(ft_alexa(tab, 3, x, y)));
	else if ((x == 1 || x == 2) && ((y == 1 || y == 2)))
		tab[x][y] = ft_str_to_char(ft_itoa(ft_alexa(tab, 4, x, y)));
	else if ((x == 1 || x == 2) && y == 3)
		tab[x][y] = ft_str_to_char(ft_itoa(ft_alexa(tab, 5, x, y)));
	else if (x == 3 && (y == 1 || y == 2))
		tab[x][y] = ft_str_to_char(ft_itoa(ft_alexa(tab, 6, x, y)));
	else if (x == 3 && y == 3)
		tab[x][y] = ft_str_to_char(ft_itoa(ft_alexa(tab, 7, x, y)));
	else if (x == 3 && y == 0)
		tab[x][y] = ft_str_to_char(ft_itoa(ft_alexa(tab, 8, x, y)));
	else if (x == 0 && y == 3)
		tab[x][y] = ft_str_to_char(ft_itoa(ft_alexa(tab, 9, x, y)));
	return (tab[x][y]);
}

char	ft_str_to_char(char *str)
{
	char	c;

	c = str[0];
	free(str);
	str = NULL;
	return (c);
}

int		ft_alexa(char **tab, int c, int x, int y)
{
	int	count;

	count = 0;
	if (c == 1 || c == 2 || c == 3 || c == 4 || c == 6 || c == 8)
	{
		if (tab[x][y + 1] != '.')
			count++;
	}
	if (c == 1 || c == 2 || c == 3 || c == 4 || c == 5 || c == 9)
	{
		if (tab[x + 1][y] != '.')
			count++;
	}
	if (c == 2 || c == 4 || c == 5 || c == 6 || c == 7 || c == 9)
	{
		if (tab[x][y - 1] != '.')
			count++;
	}
	if (c == 3 || c == 4 || c == 5 || c == 6 || c == 7 || c == 8)
	{
		if (tab[x - 1][y] != '.')
			count++;
	}
	return (count);
}
