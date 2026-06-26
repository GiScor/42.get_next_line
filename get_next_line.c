/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscorzon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 10:44:54 by gscorzon          #+#    #+#             */
/*   Updated: 2026/06/24 14:05:12 by gscorzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*str;
	/*char		*test;*/
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 1;
	/*test = malloc(BUFFER_SIZE + 1);*/
	/*test[BUFFER_SIZE] = 0;*/
	if (!buf)
	{
		buf = malloc(BUFFER_SIZE + 1);
		buf[BUFFER_SIZE] = 0;
		read(fd, buf, BUFFER_SIZE);
		str = gnl_rec(fd, buf, NULL);
		return (str);
	}
	/*while (test[i])*/
	/*{*/
			/*test[i] = buf[i];*/
			/*i++;*/
	/*}*/
	if (ft_strchr(buf, '\n') < 0 || !buf[ft_strchr(buf, '\n') + 1])
		i = read(fd, buf, BUFFER_SIZE);
	else
		ft_memmove(buf, buf+ft_strchr(buf, '\n'), BUFFER_SIZE);
	if (i == 0)
		return (NULL);
	if (*buf == '\n')
		ft_memmove(buf, buf+1, BUFFER_SIZE);
	/*if (*test != *buf)*/
	str = gnl_rec(fd, buf, NULL);
	/*else*/
			/*return (0);*/
	/*free(test);*/
	return (str);
}
