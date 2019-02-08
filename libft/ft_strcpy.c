/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 14:40:53 by hmeys             #+#    #+#             */
/*   Updated: 2018/10/27 11:40:52 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strcpy(char *dst, const char *src)
{
	int			i;
	char		*pdest;
	const char	*psrc;

	pdest = dst;
	psrc = src;
	i = 0;
	while (psrc[i])
	{
		pdest[i] = psrc[i];
		i++;
	}
	pdest[i] = psrc[i];
	return (pdest);
}
