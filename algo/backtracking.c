/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 12:28:48 by hmeys             #+#    #+#             */
/*   Updated: 2019/02/15 16:01:18 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

// NE PAS OUBLIER quand on l'appelle de deplacer de 1 le tetrominos avant.
// Pour eviter quil ne test la meme position.

int backtraking(char **tab, Tetro *new[], int *cote, char num)
{
  int i = 0;

  if (num < 0)
    return (-1);

  while (check_place(*new[num], tab) == -1)
  {
    if (new[num]->p0y == *cote && new[num]->p0x == *cote)
    {
      while (i <  4)
      {
          tab[new[num - 1]->p0x + new[num - 1]->h[i].x][new[num - 1]->p0y + new[num - 1]->h[i].y] = '.';
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
    else if (new[num]->p0y < *cote)
      new[num]->p0y++;
    else
    {
      new[num]->p0y = 0;
      new[num]->p0x++;
    }
  }
  while (i <  4)
  {
      tab[new[num]->p0x + new[num]->h[i].x][new[num]->p0y + new[num]->h[i].y] = '#';
      i++;
  }
  return (0);
}

int check_place(Tetro new, char **tab)
{
    int i;

    i = 0;
    while (tab[new.h[i].x + new.p0x][new.h[i].x + new.p0y] && i < 4)
    {
      if (tab[new.h[i].x + new.p0x][new.h[i].x + new.p0y] == '#')
        return (-1);
      i++;
    }
    return(0);
}
