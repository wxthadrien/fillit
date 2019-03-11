/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:02:18 by hmeys             #+#    #+#             */
/*   Updated: 2019/03/11 11:32:35 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int		main(int argc, char **argv)
{
	t_stock		var;
	char		**tab;
	t_tetro		*tetro;
	char		*tetro_read[5];

	var.i = 0;
	var.ret = 1;
	var.letter = 0;
	var.cote = 0;
	var.fd = open(argv[1], O_RDONLY);
	var.noot = ft_number_of_tetro(var.fd);
	close(var.fd);
	if (!(tab = malloc(sizeof(char*) * var.noot)))
		return (-1);
	if (!(tetro = malloc(sizeof(t_tetro*) * 27)))
		return (-1);
	var.fd = open(argv[1], O_RDONLY);
	ft_god(var, tab, tetro, tetro_read);
	close(var.fd);
	ft_tetro_read_free(tetro_read);
	free(tetro);
	return (0);
}

int		ft_god(t_stock var, char **tab, t_tetro *tetro, char **tetro_r)
{
	while (var.ret > 0)
	{
		var.ret = ft_read(var, var.line, tab, tetro_r);
		if (var.ret == -1)
			return (0);
		if (ft_is_valid(tetro_r) == -1)
		{
			ft_free_tab(tab, var.cote);
			return (-1);
		}
		tetro[var.letter] = ft_calcul_place(tetro_r);
		ft_tetro_read_free(tetro_r);
		while (ft_backtraking(&tab, tetro, &var.cote, var.letter) == -1)
		{
			tab = ft_next_tab(&var, tetro, tab);
			while (var.i < var.letter)
				ft_backtraking(&tab, tetro, &var.cote, var.i++);
		}
		ft_result(tab, &var);
		var.letter++;
		var.i = 0;
	}
	ft_tetro_read_free(tetro_r);
	tetro = NULL;
	return (0);
}
