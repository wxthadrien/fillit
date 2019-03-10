/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losuna-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 11:14:42 by losuna-b          #+#    #+#             */
/*   Updated: 2019/01/22 12:46:21 by losuna-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		free_all(char **a)
{
	if (a)
	{
		free(*a);
		*a = NULL;
	}
	return (-1);
}

int		check_s(char **s, char **line, int fd)
{
	int		len;
	char	*tmp;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
		if (!(*line = ft_strsub(s[fd], 0, len)))
			return (free_all(&s[fd]));
		if (!(tmp = ft_strdup(s[fd] + len + 1)))
			return (free_all(&s[fd]));
		free(s[fd]);
		s[fd] = tmp;
		return (1);
	}
	return (0);
}

int		end_of_file(char **s, char **line, int fd)
{
	if (!(*line = ft_strdup(s[fd])))
		return (free_all(&s[fd]));
	ft_strdel(&s[fd]);
	return (1);
}

int		ft_new_line(char **s, char **line, int fd)
{
	char	*tmp;
	int		len;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
		if (!(*line = ft_strsub(s[fd], 0, len)))
			return (free_all(&s[fd]));
		if (!(tmp = ft_strdup(s[fd] + len + 1)))
			return (free_all(&s[fd]));
		free(s[fd]);
		s[fd] = tmp;
	}
	else if (s[fd][len] == '\0')
		return (end_of_file(s, line, fd));
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*s[OPEN_MAX];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || line == NULL || fd > OPEN_MAX)
		return (-1);
	if (s[fd] && ((ret = check_s(s, line, fd)) != 0))
		return (ret);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (s[fd] == NULL)
			if (!(s[fd] = ft_strnew(1)))
				return (-1);
		if (!(tmp = ft_strjoin(s[fd], buf)))
			return (free_all(&s[fd]));
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if ((ret < 0) || (ret == 0 && (s[fd] == NULL || s[fd][0] == '\0')))
		return ((ret < 0) ? -1 : 0);
	return (ft_new_line(s, line, fd));
}
