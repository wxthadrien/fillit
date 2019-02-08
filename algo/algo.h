/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:43:32 by hmeys             #+#    #+#             */
/*   Updated: 2019/02/07 13:03:17 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>

typedef struct Coordonnees
{
    char x;
    char y;
} Coordonnees;

typedef struct Tetro
{
    Coordonnees h[4];
} Tetro;

char **hashtag_to_letter(char **tab, char c);
Tetro calcul_place(char **tab);
char **Placement_tetris(Tetro new);
char **Agrandir_cote(char **tab, int cote);
char **free_tab(char **tab, int n);
