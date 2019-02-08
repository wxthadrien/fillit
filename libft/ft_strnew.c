/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 11:11:36 by hmeys             #+#    #+#             */
/*   Updated: 2018/10/18 12:32:32 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	size = size + 1;
	str = (char*)malloc(size * sizeof(char));
	if (str)
	{
		ft_bzero(str, size);
		return (str);
	}
	else
		return (NULL);
}
