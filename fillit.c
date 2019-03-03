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

	i = 0;
	while (tab[i] && i < cote)
	{
		printf("%s\n", tab[i]);
		i++;
	}
	i = 0;
	return (0);
}

int ft_tetro_read_free(char **tetro_read)
{
		int i;

		i = 0;
		while(tetro_read[i])
		{
			free(tetro_read[i]);
			tetro_read[i] = NULL;
			i++;
		}
		//free(tetro_read);
		//tetro_read = NULL;
		return (0);
}

int main(int argc, char **argv)
{
	t_stock var = {0, 0, 1, 0, 0};
	char 	*line;
	char	**tab;
	t_tetro *tetro;
	char **tetro_read;
	int i = 0;

	var.fd = open(argv[1], O_RDONLY);
	var.noot = ft_number_of_tetro(var.fd);
	close(var.fd);
	if(!(tab = malloc(sizeof(char*) * var.noot)))
		return(-1);
	if(!(tetro = malloc(sizeof(t_tetro*) * 27)))
		return(-1);
	if(!(tetro_read = malloc(sizeof(char*) * 5)))
		return(-1);
		printf("tab = %p\n", tab);
		printf("tetro = %p\n", tetro);
		printf("tetro_read = %p\n", tetro_read);
	var.fd = open(argv[1], O_RDONLY);
	ft_god(var, line, tab, tetro, tetro_read);
	close(var.fd);
	//free(line);
	ft_tetro_read_free(tetro_read);
	while(i < 6)
	{
		printf("tetro_r de [i] vaut :%s\n", tetro_read[i]);
		i++;
	}
	free(tetro);
	return(0);
}

int ft_god(t_stock var, char *line, char **tab, t_tetro *tetro, char **tetro_r)
{
	while (var.ret > 0)
	{
		while ((var.ret = get_next_line(var.fd, &line)) > 0 && ft_strlen(line) > 2)
		{
			if (ft_test(line, tetro_r, var.i++) == -1)
			{
				free(line);
				line = NULL;
				return(-1);
			}
			free(line);
			line = NULL;
		}
		free(line);
		line = NULL;
		if (ft_is_valid(tetro_r) == -1)
			return (-1);
		tetro[var.letter] = ft_calcul_place(tetro_r);
		ft_tetro_read_free(tetro_r);
		//printf("ok\n");
		while (ft_backtraking(&tab, tetro, &var.cote, var.letter) == -1)
		{
			var.cote++;
			tab = ft_copier_agrandir(tab, var.cote);
			ft_clean_struct(tetro, var.letter);
			var.i = 0;
			while(var.i < var.letter)
				ft_backtraking(&tab, tetro, &var.cote, var.i++);

		}
			if (var.letter == var.noot - 1)
			{
				ft_afficher_tab(tab, var.cote);
				ft_free_tab(tab, var.cote);
			}
		var.letter++;
		var.i = 0;
	}

	ft_tetro_read_free(tetro_r);
	//ft_afficher_tab(tetro_r, 5);
	tetro = NULL;
	return(0);
}

int ft_test(char *line, char **tetro_read, int i)
{
	if (ft_vali_tab(line) == -1)
	{
		ft_putendl("error");
		free(line);
		line = NULL;
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
	//ft_tetro_read_free(tetro_read);
	return(1);
}

int ft_is_valid(char **tetro_read)
{
	if(ft_tetri_valid(ft_tab_to_str(ft_tab_converter(tetro_read))) != 0)
	{
		ft_putendl("error");
		free(tetro_read);
		return (-1);
	}
	return(1);
}
