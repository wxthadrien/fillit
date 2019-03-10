/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losuna-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 17:33:14 by losuna-b          #+#    #+#             */
/*   Updated: 2019/03/10 17:50:35 by losuna-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_test(char *line, char **tetro_read, t_stock *var, char **tab)
{
	if (ft_strlen(line) != 4)
	{
		ft_putendl("error");
		return (-1);
	}
	if (ft_vali_tab(line) == -1)
	{
		ft_free_tab(tab, var->cote);
		return (-1);
	}
	tetro_read[var->i] = ft_strdup(line);
	var->i++;
	return (1);
}

int		ft_is_valid(char **tetro_read)
{
	if (ft_tetri_valid(ft_tab_to_str(ft_tab_converter(tetro_read))) != 0)
	{
		ft_putendl("error");
		return (-1);
	}
	return (1);
}

void	ft_result(char **tab, t_stock *var)
{
	if (var->letter == var->noot - 1 && var->ret == 0)
	{
		ft_afficher_tab(tab, var->cote);
		ft_free_tab(tab, var->cote);
	}
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

char	**ft_next_tab(t_stock *var, t_tetro *tetro, char **tab)
{
	var->cote++;
	tab = ft_copier_agrandir(tab, var->cote);
	ft_clean_struct(tetro, var->letter);
	var->i = 0;
	return (tab);
}
