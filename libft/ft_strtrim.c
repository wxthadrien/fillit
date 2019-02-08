/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 10:16:43 by hmeys             #+#    #+#             */
/*   Updated: 2018/10/29 14:44:05 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	int		st;
	int		len;
	int		i;

	st = 0;
	i = 0;
	if (s != NULL)
	{
		while (((s[st] == ' ' || s[st] == '\n')
					|| (s[st] == '\t')) && (s[st] != '\0'))
			st++;
		while (s[i] != '\0')
			i++;
		len = i;
		while (((s[len - 1] == ' ' || s[len - 1] == '\n')
					|| (s[len - 1] == '\t')) && (s[st] != '\0'))
			len--;
		new = ft_strsub(s, st, len - st);
		if (new)
			return (new);
	}
	return (NULL);
}
