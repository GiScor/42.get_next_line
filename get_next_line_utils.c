/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscorzon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:09:09 by gscorzon          #+#    #+#             */
/*   Updated: 2026/07/11 16:07:55 by gscorzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*linefill(char *buf, size_t i)
{
	char	*line;
	size_t	len;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	len = i;
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
	if (found <= 0)
		return (cleanup(buf, NULL));
	line = linefill(*buf, i);
	if (ptr && ft_strlen(ptr) != ft_strlen(*buf))
		move_buf(buf, ptr);
	else if (*buf && found == 0)
		return (cleanup(buf, line));
	else
	{
		move_buf(buf, NULL);
		found = read(fd, *buf, BUFFER_SIZE);
		if (found <= 0)
			*buf = cleanup(buf, NULL);
		if (!ptr && found > 0)
			line = ft_strjoin(line, gnl(fd, buf, line, found), 0);
	}
	return (line);
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
	if (ptr)
	{
		ptr++;
		while (*ptr && (*buf)[i])
			(*buf)[i++] = *ptr++;
		if (*ptr)
			(*buf)[i] = *ptr;
	}
	while ((*buf)[i])
		(*buf)[i++] = 0;
}
