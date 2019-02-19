/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 12:28:48 by hmeys             #+#    #+#             */
/*   Updated: 2019/02/19 14:58:27 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"
char afficher_tab(char **tab, int cote);

int check_place(Tetro new, char **tab, int cote)
{
    int i;
    i = 0;

    //printf("Verifie si un hashtag depasse a droit ou en bas\n");
    while (i < 4) // check si ca sepasse a droit ou en bas
    {
      if ((new.h[i].x + new.p0x) == cote || (new.h[i].y + new.p0y) == cote)
      {
        //printf("le hashtag n%d depasse car", i);
        //printf(" les Coordonnees sont y = %d et x = %d\n", (new.h[i].y + new.p0y), (new.h[i].x + new.p0x));
        return (-1);
      }
      i++;
    }

    i = 0;

    //printf("Verifie si un hashtag depasse a gauche ou en haut\n");
    while (i < 4) // check si ca depasse a gauche ou en haut
    {
      if ((new.h[i].x + new.p0x) < 0 || (new.h[i].y + new.p0y) < 0)
      {
        //printf("le hashtag n%d depasse\n", i);
        return (-1);
      }
      i++;
    }

    i = 0;

    //printf("On verifie si la case est dispo pour chaque hashtage\n");
    while (i < 4)
    {
      if (tab[new.h[i].x + new.p0x][new.h[i].y + new.p0y] != '.')
      {
        //printf("le hashtag n%d en contiens deja un\n", i);
        return (-1);
      }
      i++;
    }
    //printf("La place est libre, return 0\n");
    return(0);
}

int backtraking(char ***tab, Tetro *new, int *cote, int num)
{
  int i = 0;
  char **tab2 = *tab;

  ////printf("new[num] contiens: p0x = %d\n", (new[0]->p0x));
  ////printf("On entre dans backtracking pour le tetrominos %d avec p0y = %d et p0x = %d\n", num, new[num].p0y, new[num].p0x);
  if (num < 0)
    return (-1);

    while (check_place(new[num], tab2, *cote) == -1)
    {
      //printf("check_place renvoi -1\n");
      if (new[num].p0y < (*cote - 1)) //on avebce
      {
        //printf("On decale à droit car p0y est a %d \n", new[num].p0y);
        new[num].p0y++;
      }

      else if (new[num].p0x < (*cote - 1)) //retourn a la ligne ATTENTION NE REDESSENT PAS A TEMPS
      {
        //printf("On decale en bas car p0x est a %d \n", new[num].p0x);
        new[num].p0y = 0;
        new[num].p0x++;
      }

      else //Fin du tab
      {
        //printf("On est a la fin du tableau pour le tetrominos %d\n", num);
        if (num == 0)
          return (-1);
        while (i <  4)
        {
            tab2[new[num - 1].p0x + new[num - 1].h[i].x][new[num - 1].p0y + new[num - 1].h[i].y] = '.';
            i++;
        }
        //printf("On affiche le tableau apres avoir enlever le dernier tetro\n");
        //afficher_tab(tab2, *cote);
        //printf("\nOK\n\n");
        i = 0;
        if (new[num - 1].p0y < (*cote - 1))
          new[num - 1].p0y++;
        else if (new[num - 1].p0x < (*cote - 1))
        {
          new[num - 1].p0y = 0;
          new[num - 1].p0x++;
        }
        // QUE FAIRE EN CAS DE FIN DE TABLEAU
        if (backtraking(tab, new, cote, num - 1) == -1)
          return (-1);
        else
        {
          new[num].p0y = 0;
          new[num].p0x = 0;
        }
      }
    }

  //printf("On place le tatro dans le tabelau !!!\n");
  while (i <  4)
  {
      tab2[new[num].p0x + new[num].h[i].x][new[num].p0y + new[num].h[i].y] = hashtag_to_letter(num);
      i++;
  }
  //afficher_tab(tab2, *cote);
  //printf("\nOK\n\n");
  return (0);
}



/*

while (check_place(new[num], tab2, *cote) == -1)
{
  //printf("check_place renvoi -1\n");
  if (new[num].p0y == *cote && new[num].p0x == *cote) //Fin du tab
  {
    //printf("On est a la fin du tableau\n");
    while (i <  4)
    {
        tab2[new[num - 1].p0x + new[num - 1].h[i].x][new[num - 1].p0y + new[num - 1].h[i].y] = '.';
        i++;
    }
    i = 0;
    if (new[num - 1].p0y < 2)
      new[num - 1].p0y++;
    else
    {
      new[num - 1].p0y = 0;
      new[num - 1].p0x++;
    }
    if (backtraking(tab, new, cote, num - 1) == -1)
      return (-1);
    else
    {
      new[num].p0y = 0;
      new[num].p0x = 0;
    }
  }
  else if (new[num].p0y < (*cote - 1)) //on avebce
  {
    //printf("On decale à droit car p0y est a %d \n", new[num].p0y);
    new[num].p0y++;
  }
  else //retourn a la ligne ATTENTION NE REDESSENT PAS A TEMPS
  {
    //printf("On decale en bas car p0x est a %d \n", new[num].p0x);
    new[num].p0y = 0;
    new[num].p0x++;
  }
}

*/
