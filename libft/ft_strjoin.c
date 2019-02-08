/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 09:55:48 by hmeys             #+#    #+#             */
/*   Updated: 2019/01/09 11:29:52 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (s1 == NULL || s2 == NULL ||
		!(new = (char*)malloc(sizeof(char) * ft_strlen(s1)
	+ ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[i] != '\0')
	{
		new[y] = s1[i];
		i++;
		y++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		new[y] = s2[i];
		i++;
		y++;
	}
	new[y] = '\0';
	return (new);
}
