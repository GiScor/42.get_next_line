#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf;
	char		**head;
	char		*str;
	int			i;

	i = 0;
	if (!buf)
	{
		buf = malloc(BUFFER_SIZE + 1);
		buf[BUFFER_SIZE] = 0;
		read(fd, buf, BUFFER_SIZE);
	}
	head = &buf;
	while (buf[i])
		i++;
	if (i < BUFFER_SIZE/2)
		ft_realloc(&buf, head);
	str = gnl_rec(fd, head, "");
	if (str)
		return (str);
	return (NULL);
}
