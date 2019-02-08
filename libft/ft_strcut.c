/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:15:27 by hmeys             #+#    #+#             */
/*   Updated: 2018/10/27 09:48:17 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcut(char *str, int go, int stop)
{
	char	*new;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (!(new = (char*)malloc(sizeof(str))) || str == NULL)
		return (NULL);
	while (i < go)
		i++;
	while (i < stop && str[i] != '\0')
	{
		new[y] = str[i];
		i++;
		y++;
	}
	new[y] = '\0';
	return (new);
}
