/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   technical.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 11:17:43 by hmeys             #+#    #+#             */
/*   Updated: 2019/03/11 11:32:01 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int		ft_number_of_tetro(int fd)
{
	int		i;
	int		ret;
	char	*buff;

	if (!(buff = malloc(sizeof(char*) * 700)))
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
	if (!(str = malloc(sizeof(char *) * 17)))
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
