#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2, size_t i)
{
	char	*s3;
	size_t	l1;
	size_t	l2;

	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	l1 = ft_strchr_gnl(s1, 0);
	l2 = ft_strchr_gnl(s2, 0);
	s3 = malloc(l1 + l2 + 1);
	if (!s3)
		return (NULL);
	while (i < l1 + l2)
	{
		if (i < l1)
			s3[i] = s1[i];
		else
			s3[i] = s2[i - l1];
		i++;
	}
	s3[l1 + l2] = 0;
	free(s1);
	free(s2);
	return (s3);
}

int	ft_strchr_gnl(const char *s, int c)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!s)
		return (-1);
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

// should arrfill actually take i? (as of now, the i parameter is useless)
char	*ft_arrfill(char *buf, size_t i)
{
	char	*arr;
	size_t	len;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	len = i;
	i = 0;
	arr = malloc(len + 1);
	if (!arr)
		return (NULL);
	arr[len] = 0;
	while (i < len)
	{
		arr[i] = buf[i];
		i++;
	}
	return (arr);
}

void	ft_movebuf(char	**buf, int n)
{
	int	end;
	int	i;

	i = 0;
	end = ft_strchr_gnl(*buf, 0);
	while (i <= n && n <= end)
	{
		(*buf)[i] = (*buf)[n];
		i++;
		n++;
	}
	while (i <= end)
	{
		(*buf)[i] = 0;
		i++;
	}
}

char	*ft_nl_handler(char *buf, char *stash, int n)
{
	int		len;
	char	*line;

	len = ft_strchr_gnl(buf, 0);
	line = ft_arrfill(buf, 0);
	if (stash)
		line = ft_strjoin(stash, line, (ft_strchr_gnl(stash, 0) + n));
	if (n < len)
		ft_movebuf(&buf, n + 1);
	return (line);
}
