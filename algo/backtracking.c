/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 12:28:48 by hmeys             #+#    #+#             */
/*   Updated: 2019/02/17 17:18:31 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

int check_place(Tetro new, char ***tab, int cote)
{
    int i;
    printf("Entre dans check_place.....");
    i = 0;


    while (tab[new.h[i].x + new.p0x][new.h[i].y + new.p0y] && i < 4) // check si ca sepasse a droit ou en bas
    {
      if ((new.h[i].x + new.p0x) == cote || (new.h[i].y + new.p0y) == cote)
        return (-1);
      i++;
    }

    i = 0;

    while (tab[new.h[i].x + new.p0x][new.h[i].y + new.p0y] && i < 4) // check si ca depasse a gauche ou en haut
    {
      if ((new.h[i].x + new.p0x) < 0 || (new.h[i].y + new.p0y) < 0)
        return (-1);
      i++;
    }

    i = 0;

    while (tab[new.h[i].x + new.p0x][new.h[i].y + new.p0y] && i < 4)
    {
      if (*tab[new.h[i].x + new.p0x][new.h[i].y + new.p0y] == '#')
      {
        printf("Le %deme tetro est un #\n", i);
        return (-1);
      }
      i++;
    }
    printf("OK\n");
    return(0);
}

int backtraking(char ***tab, Tetro **new, int *cote, int num)
{
  printf("entre dans Backtraing\n");
  int i = 0;
  char **tab2 = *tab;


  if (num < 0)
    return (-1);
  printf("Strep 1\n");
  while (check_place(*new[num], tab, *cote) == -1)
  {
    if (new[num]->p0y == *cote && new[num]->p0x == *cote) //Fin du tab
    {
      printf("Fin du tab\n");
      while (i <  4)
      {
          tab2[new[num - 1]->p0x + new[num - 1]->h[i].x][new[num - 1]->p0y + new[num - 1]->h[i].y] = '.';
          i++;
      }
      i = 0;
      if (new[num - 1]->p0y < 2)
        new[num - 1]->p0y++;
      else
      {
        new[num - 1]->p0y = 0;
        new[num - 1]->p0x++;
      }
      if (backtraking(tab, new, cote, num - 1) == -1)
        return (-1);
      else
      {
        new[num]->p0y = 0;
        new[num]->p0x = 0;
      }
    }
    else if (new[num]->p0y < *cote) //on avebce
    {
      printf("On avence\n");
      new[num]->p0y++;
    }
    else //retourn a la ligne
    {
      printf("On avence\n");
      new[num]->p0y = 0;
      new[num]->p0x++;
    }
    printf("Strep 2\n");
  }
  printf("Strep 3\n");
  while (i <  4)
  {
      tab2[new[num]->p0x + new[num]->h[i].x][new[num]->p0y + new[num]->h[i].y] = '#';
      i++;
  }

  return (0);
}
