/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:43:32 by hmeys             #+#    #+#             */
/*   Updated: 2019/03/08 15:50:13 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H
# include "../libft/libft.h"
# include <stdio.h>

typedef struct		s_coordonnees
{
	char			x;
	char			y;
}					t_coordonnees;

typedef struct		s_tetro
{
	int				p0x;
	int				p0y;
	t_coordonnees	h[4];
}					t_tetro;

typedef struct		s_calcul
{
	int				x;
	int				y;
	int				p;
	int				i;
	int				*cote;
}					t_calcul;

char				ft_hashtag_to_letter(char c);
t_tetro				ft_calcul_place(char **tab);
char				**ft_agrandir_cote(char **tab, int cote);
void				ft_free_tab(char **tab, int n);
int					ft_backtraking(char ***tab, t_tetro *new,\
					int *cote, int num);
int					ft_check_place(t_tetro new, char **tab, int cote);
int					ft_back(char **tab, int cote, t_tetro *tetro, int letter);
t_tetro				ft_pos(t_calcul pos, t_tetro position_tetro,\
					t_tetro position_absolue);
void				ft_test_back(char ***tab, t_tetro *new, char **tab2,\
					t_calcul coord);
int					ft_under_back(t_tetro *new, char **tab2, char ***tab,\
					t_calcul coord);
#endif
