/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscorzon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:01:21 by gscorzon          #+#    #+#             */
/*   Updated: 2026/07/02 17:12:23 by gscorzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf = NULL;
	char		*line;
	
	if (!buf)
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
				return (NULL);
		buf[BUFFER_SIZE] = 0;
	}
	if (!*buf)
		line = gnl(fd, buf, NULL, read(fd, buf, BUFFER_SIZE));
	line = gnl(fd, buf, NULL, 1);
	if (line == NULL && buf)
	{
		free(buf);
		return (NULL);
	}
	return (line);
}
