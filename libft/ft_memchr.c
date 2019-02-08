/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 11:54:26 by hmeys             #+#    #+#             */
/*   Updated: 2018/10/27 11:33:41 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *deref;

	deref = (unsigned char*)s;
	while (n--)
	{
		if (*deref == (unsigned char)c)
			return (deref);
		deref++;
	}
	return (0);
}
