/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscorzon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:21:56 by gscorzon          #+#    #+#             */
/*   Updated: 2026/06/24 13:59:54 by gscorzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*lalloc(char *buf)
{
	int		c;
	char	*str;

	c = 0;
	if (!*buf)
		return (NULL);
	while (buf[c] && buf[c] != '\n')
		c++;
	if (buf[c] == '\n')
		c++;
	str = malloc(c);
	str[c] = 0;
	return (str);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// str has to be alloc'd before calling gnl_rec
char	*gnl_rec(int fd, char *buf, char *str)
{
	char	*next;
	int		i;

	i = 0;
	str = lalloc(buf);
	next = str;
	while (*buf != '\n' && *buf)
		str[i++] = *buf++;
	if (*buf == '\n')
	{
		str[i] = *buf;
		buf++;
		return (str);
	}
	buf -= i;
	/*if (str[ft_strlen(str)] != '\n')*/
	/*{*/
		if (read(fd, buf, BUFFER_SIZE) == 0)
				return (0);
		next = gnl_rec(fd, buf, next);
		str = ft_strmerge(str, next);
	/*}*/
	return (str);
}

char	*ft_strmerge(char *s1, char *s2)
{
	char	*s3;
	size_t	l1;
	size_t	l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	s3 = malloc(l1 + l2 + 1);
	l1 = 0;
	l2 = 0;
	while (s1[l1])
	{
		s3[l1] = s1[l1];
		l1++;
	}
	while (s2[l2])
	{
		s3[l1 + l2] = s2[l2];
		l2++;
	}
	free(s1);
	free(s2);
	s3[l1 + l2] = 0;
	return (s3);
}

int	ft_strchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)s;
	while (ptr[i])
	{
		if (ptr[i] == (char)c)
			return (i);
		i++;
	}
	if (ptr[i] == (char)c)
		return (i);
	return (-1);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (const char *)src;
	if (!dest && !src)
		return (NULL);
	if (d > s && d < (s + n))
	{
		d += n;
		s += n;
		while (n--)
			*--d = *--s;
	}
	else
	{
		while (n--)
			*d++ = *s++;
	}
	return (dest);
}
