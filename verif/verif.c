/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lorenzo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losuna-b <losuna-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:43:48 by losuna-b          #+#    #+#             */
/*   Updated: 2019/01/21 13:54:13 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "verif.h"

char **tab_converter(char **tab) // Focntion qui convertis un tableau de . et # en tableau de chiffre pour verifier par la suite la validite du tetro.
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
      if (tab[x][y] == '#')
      {
        tab[x][y] = siri(tab, x, y);
        y++;
      }
    }
    y = 0;
    x++;
  }
  return(tab);
}

char siri(char **tab, int x, int y) // Fonction qui determine ou se trouve le # pour pouvoir verifier combien d'autre # le touche avec alexa.
{
  if (x == 0 && y == 0) // coin superieur gauche 1)
      tab[x][y] = str_to_char(ft_itoa(alexa(tab, 1, x, y)));
  else if (x == 0 && (y == 1 || y == 2)) // bord superieur 2)
      tab[x][y] = str_to_char(ft_itoa(alexa(tab, 2, x, y)));
  else if ((x == 1 || x == 2) && y == 0) // bord gauche 3)
      tab[x][y] = str_to_char(ft_itoa(alexa(tab, 3, x, y)));
  else if ((x == 1 || x == 2) && ((y == 1 || y == 2))) // centre 4)
      tab[x][y] = str_to_char(ft_itoa(alexa(tab, 4, x, y)));
  else if ((x == 1 || x == 2) && y == 3) // bord droit 5)
      tab[x][y] = str_to_char(ft_itoa(alexa(tab, 5, x, y)));
  else if (x == 3 && (y == 1 || y == 2)) // bord inferieur 6)
      tab[x][y] = str_to_char(ft_itoa(alexa(tab, 6, x, y)));
  else if (x == 3 && y == 3) // coin inferieur droit 7)
      tab[x][y] = str_to_char(ft_itoa(alexa(tab, 7, x, y)));
  else if (x == 3 && y == 0) // coin inferieur gauche 8)
      tab[x][y] = str_to_char(ft_itoa(alexa(tab, 8, x, y)));
  else if (x == 0 && y == 3) // coin suerieur droit 9)
      tab[x][y] = str_to_char(ft_itoa(alexa(tab, 9, x, y)));
  return(tab[x][y]);
}

char str_to_char(char *str) // Fonction qui transforme une string d'un caractere en char.
{
  char c;

  c = str[0];
  return(c);
}

int alexa(char **tab, int c, int x, int y) //renvoi le nombre de # qui touche celi entree en parametre.
{
  int count;

  count = 0;
  if (c == 1 || c == 2 || c == 3 || c == 4 || c == 6 || c == 8)
  {
    if (tab[x][y + 1] != '.')
      count++;
  }
  if (c == 1 || c == 2 || c == 3 || c == 4 || c == 5 || c == 9)
  {
    if (tab[x + 1][y] != '.')
      count++;
  }
  if (c == 2 || c == 4 || c == 5 || c == 6 || c == 7 || c == 9)
  {
    if (tab[x][y - 1] != '.')
      count++;
  }
  if (c == 3 || c == 4 || c == 5 || c == 6 || c == 7 || c == 8)
  {
    if (tab[x - 1][y] != '.')
      count++;
  }
  return(count);
}
