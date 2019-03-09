/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 13:15:48 by hmeys             #+#    #+#             */
/*   Updated: 2019/03/08 12:57:15 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "verif.h"
#include "../fillit.h"

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
			return (-1);
		if (t[v.x] == '.')
			v.p++;
		if (t[v.x] == '1' || t[v.x] == '2' || t[v.x] == '3')
			v.y++;
		if (t[v.x] == '2' || t[v.x] == '3')
			v.i = 1;
		v.x++;
	}
	if (v.y != 4 || v.p != 12 || v.i == 0 || ft_strlen(t) != 16)
	{
		free(t);
		return (-1);
	}
	free(t);
	return (0);
}
