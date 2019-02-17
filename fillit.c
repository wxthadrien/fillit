/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:02:18 by hmeys             #+#    #+#             */
/*   Updated: 2019/02/17 17:22:54 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	printf("\n");
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

tetro = malloc(sizeof(Tetro*) * 27);

char *n = "\n";
tab = malloc(sizeof(char*) * 27);
i = 0;
fd = open(argv[1], O_RDONLY);
while (ret > 0) //Boucle qui tourne jusqu'à ce que le fichier soit totalement lu;
{
    while ((ret = get_next_line(fd, &line)) > 0 && ft_strlen(line) > 2) //Boucle qui tourne jusqu'à ce qu'un tetro soit au complet dans tab;
	{
		if (vali_tab(line) == -1) // verifie qu'il s'agit d'une entree valide (format d'entree seulement).
			return (-1);
		if(!(tab[i] = ft_strdup(line)))
			return (-1);
		i++;
	}
    if(tetri_valid(tab_to_str(tab_converter(tab))) != 0) // Verifie qu'il s'agisse d'un tetrominos valide. ATTENTION: la fonction (t_c) modifie tab... PQ ? Possiblilites de cree une F qui met tous les chiffre avec la bonne lettre directement (A, B, ...)
        return(-1);
	      //tab = hashtag_to_letter(tab, letter);
    tetro[letter] = calcul_place(tab);
    tab = Placement_tetris(&tetro[letter], &cote);

    while (backtraking(&tab, &tetro, &cote, letter) == -1)
    {
      cote++;
      tab = Copier_Agrandir(tab, cote);
    }

    afficher_tab(tab, cote);
    //afficher_tab(tab, cote);
    //Placement_tetris(calcul_place(tab));
    return(0); //BreakPoint temporaire
	letter++;
	i = 0;
}
close(fd);
return(0);
}
