/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:02:18 by hmeys             #+#    #+#             */
/*   Updated: 2019/02/22 17:04:30 by losuna-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_number_of_tetro(int fd)
{
	int		i;
	int		ret;
	char	*buff;

	buff = malloc(sizeof(char*) * 700);
	i = read(fd, buff, 700);
	ret = -((-i - 1) / 21);
	free(buff);
	return (ret);
}

void	ft_clean_struct(t_tetro *tetro, int num)
{
	while (num >= 0)
	{
		tetro[num].p0x = 0;
		tetro[num].p0y = 0;
		num--;
	}
}

char	*ft_tab_to_str(char **tab)
{
	int		i;
	int		y;
	int		s;
	char	*str;

	s = 0;
	i = 0;
	y = 0;
	str = malloc(sizeof(char *) * 17);
	while (y < 4)
	{
		while (i < 4)
		{
			str[s] = tab[y][i];
			i++;
			s++;
		}
		i = 0;
		y++;
	}
	str[s] = '\0';
	return (str);
}

char	ft_afficher_tab(char **tab, int cote)
{
	int i;

	i = 0;
	while (tab[i] && i < cote)
	{
		printf("%s\n", tab[i]);
		i++;
	}
	i = 0;
	return (1);
}

int		main(int argc, char **argv)
{
  t_stock	var = {0, 0, 0, 1, 0, 0};
	char	*line;
	char	**tab;
	t_tetro	*tetro;
	char	**tetro_read;

	if (!(tetro = malloc(sizeof(t_tetro*) * 27)))
    return (-1);
	if (!(tab = malloc(sizeof(char*) * 27)))
    return (-1);
	if (!(tetro_read = malloc(sizeof(char*) * 5)))
    return (-1);
	var.fd = open(argv[1], O_RDONLY);
	var.no = ft_number_of_tetro(var.fd);
	close(var.fd);
	var.fd = open(argv[1], O_RDONLY);
	while (var.ret > 0)
	{
		while ((var.ret = get_next_line(var.fd, &line)) > 0 && ft_strlen(line) > 2)
		{
			if (ft_vali_tab(line) == -1)
				return (-1);
			if (!(tetro_read[var.i] = ft_strdup(line)))
				return (-1);
			var.i++;
		}
		if (ft_tetri_valid(ft_tab_to_str(ft_tab_converter(tetro_read))) != 0)
			return(-1);
		tetro[var.letter] = ft_calcul_place(tetro_read);
    while (ft_backtraking(&tab, tetro, &var.cote, var.letter) == -1)
		{
			var.cote++;
			tab = ft_copier_agrandir(tab, var.cote);
			ft_clean_struct(tetro, var.letter);
			var.i = 0;
			while (var.i < var.letter)
			{
				ft_backtraking(&tab, tetro, &var.cote, var.i);
				var.i++;
			}
		}
		if (var.letter == var.no - 1)
		{
			ft_afficher_tab(tab, var.cote);
			return (0);
		}
		var.letter++;
		var.i = 0;
	}
	close(var.fd);
	return (0);
}
