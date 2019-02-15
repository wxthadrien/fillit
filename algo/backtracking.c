/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 12:28:48 by hmeys             #+#    #+#             */
/*   Updated: 2019/02/15 14:08:59 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// NE PAS OUBLIER quand on l'appelle de deplacer de 1 le tetrominos avant.
// Pour eviter quil ne test la meme position.

int backtraking(char *tab, Tetro *new[], int *cote, char num)
{
  int i = 0;

  if (num < 0)
    return (-1);
  while (check_place(new[new], tab, cote) = -1)
  {
    if (new[num]->p0y == cote && new[num]->p0x == cote)
      return (backtraking(tab, new[], cote, num - 1));
    else if (new[num]->p0y < cote)
      new[num]->p0y++;
    else
    {
      new[num]->p0y = 0;
      new[num]->p0x++;
    }
  }
  while (i <  4)
  {
      tab[new->p0x + new->h[i].x][new->p0y + new->h[i].y] = '#';
      i++;
  }

}


int check_place(Tetro new, char **tab, int *cote)
{
  int i;

  i = 0;
  while (tab[new.h[i].x + p0x][new.h[i].x + p0y] < 4)
  {
    i++;
    if (tab[new.h[i].x + p0x] == cote && tab[new.h[i].x + p0y] == cote)
      return (-1);
    else if (i == 3)
      break ;
  }
  i = 0;
  while (tab[new.h[i].x + p0x][new.h[i].x + p0y] && i < 4)
  {
    i++;
    if (i == 3)
      return(1);
  }
  i = 0;
  return(-1);
}
