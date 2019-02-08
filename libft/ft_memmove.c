/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 11:53:51 by hmeys             #+#    #+#             */
/*   Updated: 2018/10/27 11:30:52 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*pdest;
	char	*psrc;

	pdest = (char*)dst;
	psrc = (char*)src;
	if (psrc < pdest)
	{
		psrc += len;
		pdest += len;
		while (len--)
		{
			*--pdest = *--psrc;
		}
	}
	else
	{
		while (len--)
		{
			*pdest++ = *psrc++;
		}
	}
	return (dst);
}
