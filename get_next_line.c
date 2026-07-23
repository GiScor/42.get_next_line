/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscorzon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:55:32 by gscorzon          #+#    #+#             */
/*   Updated: 2026/07/23 18:40:38 by gscorzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*buf;
	char		*line;
	int			r;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = NULL;
	r = INT_MAX;
	while (r > 0 && ft_strchr_gnl(stash, '\n') < 0)
		r = readnstash(fd, &buf, &stash);
	if (r >= 0)
		line = linefill(&stash);
	if (line == NULL && stash)
	{
		free(stash);
		stash = NULL;
	}
	return (line);
}

int	readnstash(int fd, char **buf, char **stash)
{
	ssize_t	r;

	arr_init(buf, BUFFER_SIZE);
	r = read(fd, *buf, BUFFER_SIZE);
	if (!*stash)
		arr_init(stash, r + 1);
	if (r > 0 && *stash)
		*stash = ft_strjoin(*stash, *buf, 0);
	else
	{
		free(*buf);
		*buf = NULL;
	}
	return (r);
}

char	*linefill(char **stash)
{
	char	*line;
	int		len;
	int		nl;

	if (!*stash || !**stash)
		return (NULL);
	nl = 1;
	len = ft_strchr_gnl(*stash, '\n');
	if (len < 0)
	{
		nl = 0;
		len = ft_strchr_gnl(*stash, 0);
	}
	line = malloc(len + 1 + nl);
	if (!line)
		return (NULL);
	linefillhelper(stash, &line, len, nl);
	movearr(stash, len + 1);
	return (line);
}

void	linefillhelper(char **stash, char **line, int len, int nl)
{
	int	i;

	i = 0;
	while (i < len + nl)
	{
		(*line)[i] = (*stash)[i];
		i++;
	}
	(*line)[i] = 0;
}

void	arr_init(char **arr, size_t n)
{
	size_t	i;

	*arr = malloc(n + 1);
	if (*arr)
		(*arr)[n] = 0;
	else
		return ;
	i = 0;
	while (i <= n)
	{
		(*arr)[i] = 0;
		i++;
	}
}
