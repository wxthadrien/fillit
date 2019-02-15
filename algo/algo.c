/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:40:03 by hmeys             #+#    #+#             */
/*   Updated: 2019/02/15 10:02:20 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"
char afficher_tab(char **tab, int cote);

char **hashtag_to_letter(char **tab, char c) // Fonction qui convertis le tableau de chiffre en tableau de lettre (A, B, ...).
{
    int x;
    int y;

    x = 0;
    y = 0;
    while(x < 4)
    {
        while(y < 4)
        {
            if (tab[x][y] == '.')
                y++;
            else
            {
                tab[x][y] = c;
                y++;
            }
        }
        y = 0;
        x++;
    }
    return (tab);
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

char **Placement_tetris(Tetro *new, int *cotee) //Focntion qui cree un tableau de cote * cote et y place le premier tetro.
{

    char **tab;
    int i = 0;
    int y = 0;
    int cote = 2;

    *cotee = 2;
    tab = malloc(2 * sizeof(*tab));
    if (tab == NULL)
        return (NULL);
    while(i < 2) // Boucle pour l'allocation du tableau.
    {
        tab[i] = malloc((3) * sizeof(**tab));
        i++;
    }
    i = 0;

    while(y < 2)
    {
        while(i < 2)
        {
            tab[y][i] = '.';
            i++;
        }
        i = 0;
        y++;
    }
    i = 0;

    while (i < 4) //Tetro depasse a gauche ou en haut du tableau
    {
      if ((new->p0x + new->h[i].x) >= 0 && (new->p0y + new->h[i].y) >= 0)
        i++;
      else
        {
          if (new->p0y < 2)
            new->p0y++;
          else
          {
            new->p0y = 0;
            new->p0x++;
          }
          i = 0;
        }
    }

    //new->p0x = p0x;
    //new.p0y = p0y;

    i = 0;
    if ((new->p0x + new->h[3].x) > 1 || (new->p0y + new->h[3].y) > 1 || (new->p0y + new->h[2].y) > 1 || (new->p0x + new->h[2].x) > 1) // tetro trop grand pour le tableau (depasse a droit ou en bas.
    {
        if ((new->p0x + new->h[3].x) > 2 || (new->p0y + new->h[3].y) > 2)
        {
            cote = 4;
            tab = Agrandir_cote(tab, 4); // Fonction free le tableau et en recree un de 4 de cote avec des . dedans.
            *cotee = 4;
        }
        else
        {
            cote = 3;
            tab = Agrandir_cote(tab, 3);
            *cotee = 3;
        }
        i = 0;
    }
    i = 0;
    while (i <  4)
    {
        tab[new->p0x + new->h[i].x][new->p0y + new->h[i].y] = '#';
        i++;
    }
    return(tab);
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
