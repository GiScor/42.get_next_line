#include "get_next_line.h"

/*
void	next_nl(char **head)
{
	if (ft_strchr(**head, '\n'))
	{
		while (**head != '\n')
			(*head)++;
		(*head)++;
	}
}
*/

// Alloc new memory to buf to append the new read content
size_t	ft_realloc(char **buf, char **head)
{
	size_t	len;
	char	*tmp;
	int		i;

	i = 0;
	len = 0;
	while ((*buf)[len])
		len++;
	tmp = malloc(len + 1);
	/*i = ft_strlcpy(tmp, *head, len);*/
	while ((*head)[i])
	{
		tmp[i] = (*head)[i];
		i++;
	}
	*buf = *head;
	free(*buf);
	*buf = malloc(len + BUFFER_SIZE + 1);
	(*buf)[len + BUFFER_SIZE] = 0;
	while ((*buf)[i])
	{
		tmp[i] = (*head)[i];
		i--;
	}
	*head = *buf;
	*buf += i;
	return (len + BUFFER_SIZE);
}

/*size_t	ft_strlcpy(char *dst, const char *src, size_t size)*/
/*{*/
	/*size_t	dst_len;*/
	/*size_t	i;*/

	/*i = 0;*/
	/*dst_len = 0;*/
	/*if (size < 1)*/
		/*return (ft_strlen(src));*/
	/*while (src[i] && i < size - 1)*/
	/*{*/
		/*dst[i] = src[i];*/
		/*i++;*/
	/*}*/
	/*dst[i] = 0;*/
	/*while (dst[dst_len])*/
		/*dst_len++;*/
	/*return (ft_strlen(src));*/
/*}*/

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

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
	if (read(fd, buf, BUFFER_SIZE) == 0)
		return (0);
	next = gnl_rec(fd, buf, next);
	str = ft_strmerge(str, next);
	return (str);
}

char	*ft_strmerge(char *s1, char *s2)
{
	char	*s3;
	size_t	l1;
	size_t	l2;

	l1 = 0;
	while (s1[l1++])
	l2 = 0;
	while (s2[l2++])
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
	str = malloc(c + 1);
	str[c] = 0;
	return (str);
}
