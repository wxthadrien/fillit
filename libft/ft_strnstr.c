/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 14:34:28 by hmeys             #+#    #+#             */
/*   Updated: 2018/10/27 11:56:00 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;

	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack && len > 0)
	{
		i = 0;
		while (haystack[i] && haystack[i] == needle[i])
			i++;
		if (i > len)
			return (NULL);
		if (needle[i] == '\0')
			return ((char*)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
