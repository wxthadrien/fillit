/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:02:18 by hmeys             #+#    #+#             */
/*   Updated: 2019/03/05 09:32:20 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_number_of_tetro(int fd)
{
	int		i;
	int		ret;
	char	*buff;

	if(!(buff = malloc(sizeof(char*) * 700)))
		return (-1);
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
	if(!(str = malloc(sizeof(char *) * 17)))
		return (NULL);
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

int ft_tetro_read_free(char **tetro_read)
{

		int i;

		i = 0;
		while(i < 4)
		{
			free(tetro_read[i]);
			tetro_read[i] = NULL;
			i++;
		}
		return (0);
}

int main(int argc, char **argv)
{
	t_stock var = {0, 0, 1, 0, 0};
	char 	*line;
	char	**tab;
	t_tetro *tetro;
	char *tetro_read[5];

	var.fd = open(argv[1], O_RDONLY);
	var.noot = ft_number_of_tetro(var.fd);
	close(var.fd);
	if(!(tab = malloc(sizeof(char*) * var.noot)))
		return(-1);
	if(!(tetro = malloc(sizeof(t_tetro*) * 27)))
		return(-1);
	var.fd = open(argv[1], O_RDONLY);
	ft_god(var, line, tab, tetro, tetro_read);
	close(var.fd);
	ft_tetro_read_free(tetro_read);
	free(tetro);
	return(0);
}

int ft_god(t_stock var, char *line, char **tab, t_tetro *tetro, char **tetro_r)
{
	int i;
	int y;
	int tetro_height;

	tetro_height = 0;
	i = 0;
	y = 0;
	while (var.ret > 0)
	{
		i = 0;
		while ((var.ret = get_next_line(var.fd, &line)) > 0 && ft_strlen(line) == 4)
		{
			tetro_height++;
			i = 1;
			if (y == 4)
			{
				free(line);
				line = NULL;
				ft_free_tab(tab, var.cote);
				ft_putendl("error");
				return(-1);
			}
			if (ft_test(line, tetro_r, var.i++, tab, var.cote) == -1)
			{
				free(line);
				line = NULL;
				return(-1);
			}
			free(line);
			line = NULL;
			y++;
		}
		if (tetro_height != 4)
		{
			ft_putendl("error");
			return(-1);
		}
		tetro_height = 0;
		y = 0;
		if (var.ret == -1)
		{
			ft_putendl("error");
			return(-1);
		}

		if (i == 0)
		{
			ft_putendl("error");
			free(line);
			line = NULL;
			ft_free_tab(tab, var.cote);
			return(-1);
		}
		if (var.ret > 0)
		{
			if (ft_strlen(line) != 0)
			{
				ft_putendl("error");
				free(line);
				line = NULL;
				ft_free_tab(tab, var.cote);
				return (-1);
			}
		}
		free(line);
		line = NULL;
		if (ft_is_valid(tetro_r) == -1)
		{
			ft_free_tab(tab, var.cote);
			return (-1);
		}

		tetro[var.letter] = ft_calcul_place(tetro_r);
		ft_tetro_read_free(tetro_r);
		while (ft_backtraking(&tab, tetro, &var.cote, var.letter) == -1)
		{
			var.cote++;
			tab = ft_copier_agrandir(tab, var.cote);
			ft_clean_struct(tetro, var.letter);
			var.i = 0;
			while(var.i < var.letter)
				ft_backtraking(&tab, tetro, &var.cote, var.i++);
		}
		if (var.letter == var.noot - 1 &&  var.ret == 0)
		{
			ft_afficher_tab(tab, var.cote);
			ft_free_tab(tab, var.cote);
		}
		var.letter++;
		var.i = 0;
	}
	ft_tetro_read_free(tetro_r);
	tetro = NULL;
	return(0);
}

int ft_test(char *line, char **tetro_read, int i, char **tab, int cote)
{
	if (ft_strlen(line) != 4)
	{
		ft_putendl("error");
		return(-1);
	}
	if (ft_vali_tab(line) == -1)
	{
		ft_putendl("error");
		ft_free_tab(tab, cote);
		return (-1);
	}
	if(!(tetro_read[i] = ft_strdup(line)))
	{
		ft_putendl("error");
		ft_tetro_read_free(tetro_read);
		free(line);
		line = NULL;
		return (-1);
	}
	return(1);
}

int ft_is_valid(char **tetro_read)
{
	if(ft_tetri_valid(ft_tab_to_str(ft_tab_converter(tetro_read))) != 0)
	{
		ft_putendl("error");
		return (-1);
	}
	return(1);
}
