/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscorzon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 10:44:54 by gscorzon          #+#    #+#             */
/*   Updated: 2026/06/22 15:01:23 by gscorzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*str;
	int			i;

	i = 0;
	if (!buf)
	{
		buf = malloc(BUFFER_SIZE + 1);
		buf[BUFFER_SIZE + 1] = 0;
	}
	if (*buf == '\n')
		buf++;
	if (!*buf)
		read(fd, buf, BUFFER_SIZE);
	str = lalloc(buf);
	while (*buf != '\n' && *buf)
	{
		str[i] = *buf;
		i++;
		buf++;
	}
	if (*buf)
		str[i] = *buf;
	return (str);
}
