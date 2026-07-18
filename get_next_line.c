/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscorzon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:39:21 by gscorzon          #+#    #+#             */
/*   Updated: 2026/07/18 17:53:25 by gscorzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		return (stash);
	i = ft_strchr_gnl(buf, '\n');
	if (i >= 0) 
		return (ft_nl_handler(buf, stash, i));
	else 
	{
		if (stash) 
			ft_strjoin(stash, buf, (ft_strchr_gnl(stash, 0) + ft_strchr_gnl(buf, 0)));
		else 
			stash = ft_arrfill(buf, ft_strchr_gnl(buf, 0));
		return(get_next_line(fd));
	}
	return (NULL);
}

/******************
* ft_arrfill should take `i` as an argument (it already does but it's basically a leftover);
* `i` represents how many bytes from the original array (be it buf or stash or whatever) should
* be copied over to the new array. 
* `i` will usually be the return value of ft_strchr_gnl, so either the index of nl or the lenght
* of the string.
******************/
