/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 15:06:10 by hmeys             #+#    #+#             */
/*   Updated: 2019/01/09 11:33:48 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;
	size_t	y;

	y = 0;
	i = start;
	if (!(new = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (!s)
		return (NULL);
	if (s != NULL)
	{
		while (y < len)
		{
			new[y] = s[i];
			y++;
			i++;
		}
		new[y] = '\0';
	}
	return (new);
}
