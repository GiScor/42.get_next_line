#include "get_nexxt_line.h"

char    *ft_strjoin(char *s1, char *s2, size_t i)
{
    char    *s3;
    size_t  l1;
    size_t  l2;

    if (!s1)
        return (s2);
    if (!s2)
        return (s1);
    l1 = ft_strlen(s1);
    l2 = ft_strlen(s2);
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

int    ft_strchr_gnl(const char *s, int c)
{
    char    *ptr;
	int		i;

	i = 0;
    if (!s)
        return (NULL);
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

char    *ft_arrfill(char *stash, char *buf, size_t i)
{
    char    *arr;
    size_t  len;

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
