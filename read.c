/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losuna-b <losuna-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 18:41:16 by losuna-b          #+#    #+#             */
/*   Updated: 2019/03/11 13:07:52 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_read(t_stock v, char *ln, char **tab, char **tetro_r)
{
	int y;

	y = 0;
	while ((v.ret = get_next_line(v.fd, &ln)) > 0 && ft_strlen(ln) == 4)
	{
		if (y == 4)
			return (er(3, tab, v.cote, ln));
		if (ft_test(ln, tetro_r, &v, tab) == -1)
			return (er(2, tab, v.cote, ln));
		ft_strdel(&ln);
		y++;
	}
	if (v.ret == -1)
		return (er(0, tab, v.cote, ln));
	if (y == 0)
		return ((v.ret == 1) ? er(3, tab, v.cote, ln) : er(1, tab, v.cote, ln));
	if (v.ret > 0)
		if (ft_strlen(ln) != 0)
			return (er(3, tab, v.cote, ln));
	ft_strdel(&ln);
	if (y != 4)
		return (er(1, tab, v.cote, ln));
	y = 0;
	return (v.ret);
}

char	ft_afficher_tab(char **tab, int cote)
{
	int i;
	int y;

	y = 0;
	i = 0;
	while (tab[i] && i < cote)
	{
		while (tab[i][y] && y < cote)
		{
			ft_putchar(tab[i][y]);
			y++;
		}
		ft_putchar('\n');
		y = 0;
		i++;
	}
	return (0);
}

int		ft_tetro_read_free(char **tetro_read)
{
	int i;

	i = 0;
	while (i < 4)
	{
		free(tetro_read[i]);
		tetro_read[i] = NULL;
		i++;
	}
	return (0);
}

int		ft_free(char *s)
{
	free(s);
	s = NULL;
	return (-1);
}

int		er(int cas, char **tab, int cote, char *line)
{
	if (cas == 2 || cas == 3)
	{
		free(line);
		line = NULL;
	}
	if (cas == 1 || cas == 3)
	{
		ft_free_tab(tab, cote);
	}
	ft_putendl("error");
	return (-1);
}
