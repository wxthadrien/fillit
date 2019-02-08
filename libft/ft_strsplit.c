/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 13:02:59 by hmeys             #+#    #+#             */
/*   Updated: 2019/01/09 11:33:03 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_free(char **str, int len)
{
	while (len > 0)
	{
		free(str[len]);
		str[len] = NULL;
		len--;
	}
	free(str);
	str = NULL;
	return (NULL);
}

static	int		ft_count_words(const char *str, char c)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			word++;
		i++;
	}
	if (str[0] != '\0')
		word++;
	return (word);
}

static	char	*ft_word(const char *str, char c, int *i)
{
	char	*s;
	int		k;

	if (!(s = (char *)malloc(sizeof(char) * (ft_strlen((char*)str)))))
		return (NULL);
	k = 0;
	while (str[*i] != c && str[*i])
	{
		s[k] = str[*i];
		k++;
		*i += 1;
	}
	s[k] = '\0';
	while (str[*i] == c && str[*i])
		*i += 1;
	return (s);
}

char			**ft_strsplit(const char *str, char c)
{
	int		i;
	int		j;
	int		wrd;
	char	**s;

	i = 0;
	j = 0;
	if (str == NULL)
		return (NULL);
	wrd = ft_count_words(str, c);
	if (!(s = (char **)malloc(sizeof(char *) * (ft_count_words(str, c) + 2))))
		return (NULL);
	while (str[i] == c && str[i])
		i++;
	while (j < wrd && str[i])
	{
		if (!(s[j] = ft_word(str, c, &i)))
		{
			ft_free(s, j);
			return (NULL);
		}
		j++;
	}
	s[j] = NULL;
	return (s);
}
