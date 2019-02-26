/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:43:32 by hmeys             #+#    #+#             */
/*   Updated: 2019/02/22 16:33:24 by losuna-b         ###   ########.fr       */
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

char				ft_hashtag_to_letter(char c);
t_tetro				ft_calcul_place(char **tab);
char				**ft_agrandir_cote(char **tab, int cote);
char				**ft_free_tab(char **tab, int n);
int					ft_backtraking(char ***tab, t_tetro *new, int *cote,
					int num);
int					ft_check_place(t_tetro new, char **tab, int cote);
int ft_back(char **tab, int cote, t_tetro *tetro, int letter);
#endif
