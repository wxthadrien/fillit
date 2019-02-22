/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:03:17 by hmeys             #+#    #+#             */
/*   Updated: 2019/02/22 16:48:15 by losuna-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERIF_H
# define VERIF_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include "../libft/libft.h"

int		ft_vali_tab(char *line);
char	**ft_tab_converter(char **tab);
char	ft_siri(char **tab, int x, int y);
char	ft_str_to_char(char *str);
int		ft_alexa(char **tab, int c, int x, int y);
int		ft_tetri_valid(char *tab);
#endif
