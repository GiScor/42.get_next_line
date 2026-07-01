/*	TODO
 *
 	*	Se buf inizia con '\n'
 	*	ptr punta a '\n', quando facciamo memmove buf inizia con '\n'
	*	La porcoddio di norma
	*	Posso mettere funzioni anche in get_next_line.c?
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	l1;
	size_t	l2;
	size_t	i;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	s3 = malloc((l1 + l2) * sizeof(char) + 1);
	if (!s3)
		return (NULL);
	i = 0;
	while (i < l1)
	{
		s3[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < l2)
	{
		s3[i + l1] = s2[i];
		i++;
	}
	s3[i + l1] = 0;
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

char	*gnl(int fd, char *buf, char *line, int found)
{
	size_t		i;
	char		*ptr;

	i = 0;
	ptr = ft_strchr(buf, '\n');
	while(buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	if (found > 0)
		line = linefill(buf, i);
	if (ptr && i != ft_strlen(buf))
	{
		i = 0;
		while(*ptr && buf[i])
			buf[i++] = *ptr++;
		buf[i] = *ptr;
		while(buf[i])
			buf[i++] = 0;
	}
	else if (!ptr)
	{
		if (found > 0)
			found = read(fd, buf, BUFFER_SIZE);
		line = ft_strjoin(line, gnl(fd, buf, line, found));
	}
	if (found > 0)
		return (line);
	return (NULL);
}
