/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:02:18 by hmeys             #+#    #+#             */
/*   Updated: 2019/02/19 15:34:52 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int number_of_tetro(int fd)
{
  int i;
  int ret;
  char *buff;
  buff = malloc(sizeof(char*) * 700);
  i = read(fd, buff, 700);

  ret = -((-i - 1) / 21);
  free(buff);
  return (ret);
}

void clean_struct(Tetro *tetro, int num)
{
  while (num >= 0)
  {
    tetro[num].p0x = 0;
    tetro[num].p0y = 0;
    num--;
  }
}

char *tab_to_str(char **tab)
{
    int i;
    int y;
    int s;
    char *str;

    s = 0;
    i = 0;
    y = 0;
    str = malloc(sizeof(char *) * 17);
    while(y < 4)
    {
        while(i < 4)
        {
            str[s] = tab[y][i];
            i++;
            s++;
        }
        i = 0;
        y++;
    }
    str[s] = '\0';
    return(str);
}

char afficher_tab(char **tab, int cote)
{
	int i = 0;

	while (tab[i] && i < cote)
	{
		printf("%s\n", tab[i]);
		i++;
	}
	i = 0;
return (1);
}

int main(int argc, char **argv) // fonction principal qui lis le fichier, place le tetro dans un tableau, verifie la validité du tetro et appelle l'algorithme de resolution. ATTENTION segfault avec plusieur tetri
{
int 	i = 0;
int		fd;
char 	*line;
char	**tab;
int		ret = 1;
int  letter = 0;
Tetro *tetro;
int   cote = 0;
char **tetro_read;
int not;

tetro = malloc(sizeof(Tetro*) * 27);

char *n = "\n";
tab = malloc(sizeof(char*) * 27);
tetro_read = malloc(sizeof(char*) * 5);
i = 0;
fd = open(argv[1], O_RDONLY);
not = number_of_tetro(fd);
close(fd);
fd = open(argv[1], O_RDONLY);
while (ret > 0) //Boucle qui tourne jusqu'à ce que le fichier soit totalement lu;
{
  while ((ret = get_next_line(fd, &line)) > 0 && ft_strlen(line) > 2) //Boucle qui tourne jusqu'à ce qu'un tetro soit au complet dans tab;
	{
		if (vali_tab(line) == -1) // verifie qu'il s'agit d'une entree valide (format d'entree seulement).
			return (-1);
		if(!(tetro_read[i] = ft_strdup(line)))
			return (-1);
		i++;
	}
    if(tetri_valid(tab_to_str(tab_converter(tetro_read))) != 0) // Verifie qu'il s'agisse d'un tetrominos valide. ATTENTION: la fonction (t_c) modifie tab... PQ ? Possiblilites de cree une F qui met tous les chiffre avec la bonne lettre directement (A, B, ...)
        return(-1);
	      //tab = hashtag_to_letter(tab, letter);
    tetro[letter] = calcul_place(tetro_read);

      //printf("P0x = %d, p0y = %d, h4.x = %d, h4.y = %d, cote = %d, letter = %d\n", tetro[letter].p0x, tetro[letter].p0y, tetro[letter].h[1].x, tetro[letter].h[1].y, cote, letter);


      while (backtraking(&tab, tetro, &cote, letter) == -1)
      {
        cote++;
        tab = Copier_Agrandir(tab, cote);
        //afficher_tab(tab, cote); // COPIER AGRANDIR LE REPLACE PAS LES TETRO PRECEDENT
        clean_struct(tetro, letter);
        i = 0;
        while(i < letter)
        {
          backtraking(&tab, tetro, &cote, i);
          i++;
        }
      }
    if (letter == not - 1)
    {
      afficher_tab(tab, cote);
      return (0);
    }
    //afficher_tab(tab, cote);
    //Placement_tetris(calcul_place(tab));
    //BreakPoint temporaire
	letter++;
	i = 0;
}
close(fd);
return(0);
}
