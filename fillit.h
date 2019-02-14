/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:03:17 by hmeys             #+#    #+#             */
/*   Updated: 2019/02/14 11:29:41 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft/libft.h"
# include "verif/verif.h"
# include "algo/algo.h"
# include "get_next_line/get_next_line.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

char afficher_tab(char **tab, int cote);
int main(int argc, char **argv);
char *tab_to_str(char **tab);
