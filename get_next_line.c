/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscorzon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:01:21 by gscorzon          #+#    #+#             */
/*   Updated: 2026/07/11 13:04:10 by gscorzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf = NULL;
	char		**ptr;
	char		*line;

	if (buf == ((char *) 1))
		return (NULL);
	if (!buf)
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		ft_memset(buf, 0, BUFFER_SIZE + 1);
	}
	ptr = &buf;
	if (*buf == 0)
		line = gnl(fd, ptr, NULL, read(fd, buf, BUFFER_SIZE));
	else
		line = gnl(fd, ptr, NULL, 1);
	if (line == NULL)
	{
		buf = ((char *) 1);
		return (NULL);
	}
	return (line);
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

void	ft_memset(char *s, int c, size_t n)
{
	while (n--)
		*s++ = c;
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
