/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:40:03 by hmeys             #+#    #+#             */
/*   Updated: 2019/02/19 13:27:29 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"
char afficher_tab(char **tab, int cote);

char hashtag_to_letter(char c) // Fonction qui convertis le tableau de chiffre en tableau de lettre (A, B, ...).
{
  char ret;

  ret = (c + 65);
  return (ret);
}

Tetro calcul_place(char **tab) // Calcul premierement la postion relative du tetro puis la position absolue et la renvoi
{
    Tetro position_tetro = {0, 0};
    Tetro position_absolue = {0, 0};
    int x;
    int y;
    int p;

    x = 0;
    y = 0;
    p = 0;
    while(x < 4)
    {
        while(y < 4)
        {
            if (tab[x][y] == '.')
                y++;
            else
            {
                position_tetro.h[p].x = x;
                position_tetro.h[p].y = y;
                y++;
                p++;
            }
        }
        y = 0;
        x++;
    }
    // Faire un boucle pour completer
    position_absolue.h[0].x = 0 ;
    position_absolue.h[1].x = position_tetro.h[1].x - position_tetro.h[0].x;
    position_absolue.h[2].x = position_tetro.h[2].x - position_tetro.h[0].x;
    position_absolue.h[3].x = position_tetro.h[3].x - position_tetro.h[0].x;

    position_absolue.h[0].y = 0 ;
    position_absolue.h[1].y = position_tetro.h[1].y - position_tetro.h[0].y;
    position_absolue.h[2].y = position_tetro.h[2].y - position_tetro.h[0].y;
    position_absolue.h[3].y = position_tetro.h[3].y - position_tetro.h[0].y;

    position_absolue.p0x = 0;
    position_absolue.p0y = 0;
    //printf("La position absolue du h 0 du tetro est de x= %d y= %d\n", position_absolue.h[0].x, position_absolue.h[0].y);
    //printf("La position absolue du h 1 du tetro est de x= %d y= %d\n", position_absolue.h[1].x, position_absolue.h[1].y);
    //printf("La position absolue du h 2 du tetro est de x= %d y= %d\n", position_absolue.h[2].x, position_absolue.h[2].y);
    //printf("La position absolue du h 3 du tetro est de x= %d y= %d\n", position_absolue.h[3].x, position_absolue.h[3].y);

    return(position_absolue);
}

char **Agrandir_cote(char **tab, int cote)
{
    int i = 0;
    int y = 0;

    free_tab(tab, (2));
    tab = malloc(cote * sizeof(*tab));
    if (tab == NULL)
        return (NULL);
    while(i < cote) // Boucle pour l'allocation du tableau.
    {
        tab[i] = malloc((cote + 1) * sizeof(**tab));
        i++;
    }
    i = 0;
    while(y < cote)
    {
        while(i < cote)
        {
            tab[y][i] = '.';
            i++;
        }
        i = 0;
        y++;
    }
    return (tab);
}

char **free_tab(char **tab, int n)
{
    int i;

    i = 0;

    while (i < n)
    {
        free(tab[i]);
        tab[i] = NULL;
        i++;
    }
    free(tab);
    tab = NULL;
    return (tab);
}

char **Copier_Agrandir(char **tab, int cote)
{
    int i = 0;
    int y = 0;
    char **new_tab;

    new_tab = malloc(cote * sizeof(*new_tab));
    if (new_tab == NULL)
        return (NULL);
    while(i < cote) // Boucle pour l'allocation du tableau.
    {
        new_tab[i] = malloc((cote + 1) * sizeof(**new_tab));
        i++;
    }
    i = 0;
    while(y < cote)
    {
        while(i < cote)
        {
          if (i < (cote - 1) && y < (cote - 1))
          {
            if (tab[y][i] == '#')
              new_tab[y][i] = '#';
            else
              new_tab[y][i] = '.';
          }
          else
            new_tab[y][i] = '.';
            i++;
        }
        i = 0;
        y++;
    }
    free_tab(tab, (cote - 1));
    return (new_tab);
}
