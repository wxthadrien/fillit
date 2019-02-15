/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:43:32 by hmeys             #+#    #+#             */
/*   Updated: 2019/02/15 16:01:34 by hmeys            ###   ########.fr       */
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
    int p0x;
    int p0y;
    Coordonnees h[4];
} Tetro;

char **hashtag_to_letter(char **tab, char c);
Tetro calcul_place(char **tab);
char **Placement_tetris(Tetro *new, int *cotee);
char **Agrandir_cote(char **tab, int cote);
char **free_tab(char **tab, int n);
int backtraking(char **tab, Tetro *new[], int *cote, char num);
int check_place(Tetro new, char **tab);
