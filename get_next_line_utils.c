/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscorzon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:09:09 by gscorzon          #+#    #+#             */
/*   Updated: 2026/07/01 15:14:47 by gscorzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	i;
	size_t	l1;
	size_t	l2;

	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	s3 = malloc((l1 + l2) + 1);
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
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (s3);
}

/*char	*gnl_rec(int fd, char *buf, char *o_line)*/
char	*gnl_rec(int fd, char *buf, int status)
{
	char	*ptr;
	char	*line;
	int		i;

	if (status <= 0)
		buf = NULL;
	i = 0;
	ptr = ft_strchr(buf, '\n');
	if (!ptr)
	{
		line = linefill(buf, ptr);
		status = read(fd, buf, BUFFER_SIZE);
		line = ft_strjoin(line, gnl_rec(fd, buf, status));
	}
	if (ptr)
		line = linefill(buf, ptr);
	if (ptr && ptr != &buf[BUFFER_SIZE]) 
	{
		if (*buf == ptr[i])
			ptr = buf + 1;
		while (ptr[i])
		{
			buf[i] = ptr[i];
			i++;
		}
		buf[i] = ptr[i];
		while (buf[i])
			buf[i++] = 0;
		return (line);
	}
	if (ptr && ptr == &buf[BUFFER_SIZE])
		status = read(fd, buf, BUFFER_SIZE);
	return (line);
}

char	*linefill(char *buf, char *ptr)
{
	char	*line;
	int		i;
	size_t	len;

	i = 0;
	if (ptr)
		len = (int)(ptr - buf);
	else
		len = BUFFER_SIZE;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	line[len] = 0;
	while (buf [i] && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	line[i] = '\n';
	return (line);
}
