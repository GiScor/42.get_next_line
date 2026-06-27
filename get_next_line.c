/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscorzon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 10:44:54 by gscorzon          #+#    #+#             */
/*   Updated: 2026/06/27 12:22:48 by gscorzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*str;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 1;
	if (!buf)
	{
		buf = malloc(BUFFER_SIZE + 1);
		buf[BUFFER_SIZE] = 0;
		read(fd, buf, BUFFER_SIZE);
		str = gnl_rec(fd, buf, NULL);
		return (str);
	}
	if (ft_strchr(buf, '\n') < 0 || !buf[ft_strchr(buf, '\n') + 1])
		i = read(fd, buf, BUFFER_SIZE);
	else
		ft_memmove(buf, buf+ft_strchr(buf, '\n'), BUFFER_SIZE);
	if (i == 0)
		return (NULL);
	if (*buf == '\n')
		ft_memmove(buf, buf+1, BUFFER_SIZE);
	str = gnl_rec(fd, buf, NULL);
	return (str);
}
