/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscorzon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:56:23 by gscorzon          #+#    #+#             */
/*   Updated: 2026/07/11 13:01:19 by gscorzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

//# ifndef GNL_DONE

//#  define GNL_DONE (char *)1

//#endif // GNL_DONE

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 100

# endif // BUFFER_SIZE

# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*linefill(char *buf, int len);
char	*gnl(int fd, char **buf, char *line, int found);
void	ft_memset(char *s, int c, size_t n);
char	*cleanup(char **buf, char *line);
void	move_buf(char **buf, char *ptr);

#endif // GET_NEXT_LINE_H
