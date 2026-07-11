/*	TODO
 *
	 * Non funziona senza nl finale (double free)
 *
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscorzon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:09:09 by gscorzon          #+#    #+#             */
/*   Updated: 2026/07/01 16:30:32 by gscorzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s || !*s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	if (!s)
		return (NULL);
	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == (char)c)
			return (ptr);
		ptr++;
	}
	if (*ptr == (char)c)
		return (ptr);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	l1;
	size_t	l2;
	size_t	i;

	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	s3 = malloc((l1 + l2) + 1);
	if (!s3)
		return (NULL);
	s3[l1 + l2] = 0;
	i = 0;
	while (i < l1)
	{
		s3[i] = s1[i];
		i++;
	}
	free(s1);
	i = 0;
	while (i < l2)
	{
		s3[i + l1] = s2[i];
		i++;
	}
	free(s2);
	return (s3);
}

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

	if (*buf == GNL_DONE)
		return (NULL);
	i = 0;
	ptr = ft_strchr(*buf, '\n');
	while((*buf)[i] && (*buf)[i] != '\n')
		i++;
	if ((*buf)[i] == '\n')
		i++;
	if (found > 0)
		line = linefill(*buf, i);
	else
	{
		free(*buf);
		*buf = GNL_DONE;
		return (NULL);
	}
	if (ptr && i != ft_strlen(*buf))
	{
		ptr++;
		i = 0;
		while(*ptr && (*buf)[i])
			(*buf)[i++] = *ptr++;
		if (*ptr)
			(*buf)[i] = *ptr;
		while((*buf)[i])
			(*buf)[i++] = 0;
	}
	else if ((*buf && found < BUFFER_SIZE) || (!ptr && found > 0))
	{
		if (*buf && found < BUFFER_SIZE)
		{
			free(*buf);
			*buf = GNL_DONE;
			return (line);
		}
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
