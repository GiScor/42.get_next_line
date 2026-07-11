/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscorzon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:09:09 by gscorzon          #+#    #+#             */
/*   Updated: 2026/07/11 13:04:14 by gscorzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*linefill(char *buf, int len)
{
	char	*line;
	int		i;

	if (!buf)
		return (NULL);
	i = 0;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	line[len] = 0;
	while (i < len)
	{
		line[i] = buf[i];
		i++;
	}
	return (line);
}

char	*gnl(int fd, char **buf, char *line, int found)
{
	size_t		i;
	char		*ptr;

	if (*buf == ((char *) 1))
		return (NULL);
	i = 0;
	ptr = ft_strchr(*buf, '\n');
	while ((*buf)[i] && (*buf)[i] != '\n')
		i++;
	if ((*buf)[i] == '\n')
		i++;
	if (found > 0)
		line = linefill(*buf, i);
	else
		return (cleanup(buf, NULL));
	if (ptr && i != ft_strlen(*buf))
		move_buf(buf, ptr);
	else if ((*buf && found < BUFFER_SIZE) || (!ptr && found > 0))
	{
		if (*buf && found == 0)
			return (cleanup(buf, line));
		found = read(fd, *buf, BUFFER_SIZE);
		line = ft_strjoin(line, gnl(fd, buf, line, found));
	}
	else
	{
		found = read(fd, *buf, BUFFER_SIZE);
		if (found <= 0)
			(*buf)[0] = 0;
	}
	if (found > 0 || (*buf && found < BUFFER_SIZE))
		return (line);
	return (NULL);
}

char	*cleanup(char **buf, char *line)
{
	free(*buf);
	*buf = ((char *) 1);
	return (line);
}

void	move_buf(char **buf, char *ptr)
{
	int	i;

	i = 0;
	ptr++;
	while (*ptr && (*buf)[i])
		(*buf)[i++] = *ptr++;
	if (*ptr)
		(*buf)[i] = *ptr;
	while ((*buf)[i])
		(*buf)[i++] = 0;
}
