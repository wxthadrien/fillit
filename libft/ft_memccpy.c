/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 11:52:27 by hmeys             #+#    #+#             */
/*   Updated: 2018/10/27 11:28:05 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*pdest;
	unsigned char	*psrc;
	unsigned char	pc;

	pdest = (unsigned char*)dst;
	psrc = (unsigned char*)src;
	pc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		pdest[i] = psrc[i];
		if (pdest[i] == pc)
			return (pdest + i + 1);
		i++;
	}
	return (NULL);
}
