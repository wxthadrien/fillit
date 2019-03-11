/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losuna-b <losuna-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 18:41:16 by losuna-b          #+#    #+#             */
/*   Updated: 2019/03/11 11:36:28 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_read(t_stock var, char *line, char **tab, char **tetro_r)
{
	int y;

	y = 0;
	while ((var.ret = get_next_line(var.fd, &line)) > 0 && ft_strlen(line) == 4)
	{
		if (y == 4)
			return (error_return(3, tab, var.cote, line));
		if (ft_test(line, tetro_r, &var, tab) == -1)
			return (error_return(2, tab, var.cote, line));
		ft_strdel(&line);
		y++;
	}
	if (var.ret == -1)
		return (error_return(0, tab, var.cote, line));
	if (y == 0)
		return ((var.ret == 1) ? error_return(3, tab, var.cote, line) : \
				error_return(1, tab, var.cote, line));
	if (var.ret > 0)
		if (ft_strlen(line) != 0)
			return (error_return(3, tab, var.cote, line));
	ft_strdel(&line);
	if (y != 4)
		return (error_return(1, tab, var.cote, line));
	y = 0;
	return (var.ret);
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

int		error_return(int cas, char **tab, int cote, char *line)
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
