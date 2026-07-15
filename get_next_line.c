#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf = NULL;
	static char	*stash = NULL;
	int			status;
	int			i;
	
	if (!buf)
	{
		buf = malloc(BUFFER_SIZE + 1);
		buf[BUFFER_SIZE] = 0;
	}
	status = read(fd, buf, BUFFER_SIZE);
	if (status <= 0)
		return (stash);// WARNING: if stash is empty it must also be free'd and set to NULL;
	i = ft_strchr_gnl(buf, '\n');
	if (i >= 0)
		return (ft_nl_handler(buf, stash, i));// if there's a nl, ft_nl_handler handles it (nl at end or middle)
	else// if there is no nl
	{
		if (stash)
			ft_strjoin(stash, buf);// if there is content stashed, join it with current buf
		else
			stash = ft_arrfill(buf, ft_strchr_gnl(buf, 0));// if stash is empty, fill it with current buf content
		return(get_next_line(fd));
	}
	return (NULL);
}
/***********************
 * FUNCTIONS TO WRITE
 * 	ft_nl_handler
 ***********************/
