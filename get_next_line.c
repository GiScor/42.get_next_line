/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscorzon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:39:21 by gscorzon          #+#    #+#             */
/*   Updated: 2026/07/18 18:31:44 by gscorzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*buf;
	int			i;

	buf = NULL;
	buf_init(&buf, &stash);
	if (buf == NULL)
		return (NULL);
	line = ft_newline(&buf, &stash);
	free(buf);
	return(line);
}

char	*ft_newline(char **buf, char **stash)
{
	int		b_len;

	b_len = ft_strchr_gnl(*buf, 0);
	if (ft_strchr_gnl(*buf, '\n') < 0)
		*stash = ft_strjoin(*stash, *buf, ft_strchr_gnl(*stash, 0) + b_len);
	else // there is newline in *buf
		
}



void	buf_init(int fd, char **buf, char **stash)
{
	int	status;

	if (!*buf)
	{
		*buf = malloc(BUFFER_SIZE + 1);
		if (*buf)
			(*buf)[BUFFER_SIZE] = 0;
		else
			return ;
	}
	status = read(fd, *buf, BUFFER_SIZE);
	if (status > 0)
		(*buf)[status] = 0;
	else if (status <= 0)
		eof_helper(buf, stash);
}

void	eof_helper(char **buf, char **stash)
{
	free(*buf);
	*buf = NULL;
	if (*stash)
	{
		*buf = ft_arrfill(*stash, ft_strchr_gnl(*stash, 0));
		free(*stash);
		*stash = NULL;
	}
}
