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
	char		*test;
	int			i;

	i = 0;
	test = malloc(BUFFER_SIZE + 1);
	test[BUFFER_SIZE] = 0;
	while (test[i])
	{
			test[i] = buf[i];
			i++;
	}
	if (!buf)
	{
		buf = malloc(BUFFER_SIZE + 1);
		buf[BUFFER_SIZE] = 0;
	}
	if (*buf == '\n')
		buf++;
	read(fd, buf, BUFFER_SIZE);
	if (*test != *buf)
			str = gnl_rec(fd, buf, "");
	else
			return (0);
	return (str);
}
