/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscorzon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:01:21 by gscorzon          #+#    #+#             */
/*   Updated: 2026/07/06 16:59:21 by gscorzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf = NULL;
	char		*line;
	
	if (buf == GNL_DONE)
		return (NULL);
	if (!buf)
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
				return (NULL);
		ft_memset(buf, 0, BUFFER_SIZE + 1);
	}
	/*printf("\n%d\n", *buf);*/
	if (*buf == 0)
		line = gnl(fd, buf, NULL, read(fd, buf, BUFFER_SIZE));
	else
		line = gnl(fd, buf, NULL, 1);
	if (line == NULL)
	{
		free(buf);
		buf = GNL_DONE;
		return (NULL);
	}
	return (line);
}

void	ft_memset(char *s, int c, size_t n)
{
	while (n--)
		*s++ = c;
}
