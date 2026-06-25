#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf;
	char		**head;
	char		*str;

	if (!buf)
	{
		buf = malloc(BUFFER_SIZE + 1);
		buf[BUFFER_SIZE] = 0;
	}
	head = &buf;
	str = gnl_rec(fd, *head, "");
	if (str)
		return (str);
	return (NULL);
}
