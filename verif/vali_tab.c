/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vali_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 17:03:52 by hmeys             #+#    #+#             */
/*   Updated: 2019/01/21 13:26:19 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "verif.h"

int vali_tab(char *line) //Fonction qui verifie que l'entree est bonne: 16 char et uniquement les . et #.
{
  int i;

  i = 0;
  if (ft_strlen(line) != 4)
    return (-1);
  while (i < 4)
  {
    if (line[i] != '.' && line[i] != '#')
      return (-1);
    i++;
  }
  return(0);
}
