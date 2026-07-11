/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscorzon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:01:21 by gscorzon          #+#    #+#             */
/*   Updated: 2026/07/11 11:53:32 by gscorzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf = NULL;
	char		**ptr;
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
	ptr = &buf;
	if (*buf == 0)
		line = gnl(fd, ptr, NULL, read(fd, buf, BUFFER_SIZE));
	else
		line = gnl(fd, ptr, NULL, 1);
	if (line == NULL)
	{
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
