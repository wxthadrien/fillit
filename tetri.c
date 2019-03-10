/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losuna-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 17:43:11 by losuna-b          #+#    #+#             */
/*   Updated: 2019/03/10 17:43:14 by losuna-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_tetri_valid(char *t)
{
	t_calcul v;

	v.i = 0;
	v.y = 0;
	v.p = 0;
	v.x = 0;
	while (t[v.x] && t[v.x] != '\n')
	{
		if (t[v.x] != '.' && t[v.x] != '1' && t[v.x] != '2' && t[v.x] != '3')
			return (ft_free(t));
		if (t[v.x] == '.')
			v.p++;
		if (t[v.x] == '1' || t[v.x] == '2' || t[v.x] == '3')
			v.y++;
		if (t[v.x] == '2' || t[v.x] == '3')
			v.i = 1;
		v.x++;
	}
	if (v.y != 4 || v.p != 12 || v.i == 0 || ft_strlen(t) != 16)
		return (ft_free(t));
	free(t);
	return (0);
}

int		ft_vali_tab(char *line)
{
	int	i;

	i = 0;
	if (ft_strlen(line) != 4)
		return (-1);
	while (i < 4)
	{
		if (line[i] != '.' && line[i] != '#')
			return (-1);
		i++;
	}
	return (0);
}
