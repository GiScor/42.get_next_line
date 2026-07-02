/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscorzon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:01:21 by gscorzon          #+#    #+#             */
/*   Updated: 2026/07/02 17:18:16 by gscorzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf = NULL;
	char		*line;
	int 		found;
	
	if (!buf)
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
				return (NULL);
		buf[BUFFER_SIZE] = 0;
	}
	found = read(fd, buf, BUFFER_SIZE); 
	if (!*buf)
		line = gnl(fd, buf, NULL, found);
	line = gnl(fd, buf, NULL, 1);
	if (line == NULL && buf)
	{
		free(buf);
		buf = found;
		return (NULL);
	}
	return (line);
}
